#include "modules/module.hpp"
#include <ctime>
#include <iomanip>
#include <chrono>
#include <stdlib.h>
#include "modules/exception.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

ModuleMap modules;

namespace JAM::MODULE{
	Module::Module(std::string id) : id(id), index(modules.size()){	modules.push_back(this);	}

	void Module::configure(Json::config::Config &cfg){
		for(Json::config::SettingMap::iterator i = _settings.begin(); i != _settings.end(); i++){
			Json::config::Setting &cfgSetting = cfg[i->first];
			Json::config::Setting &defaultValue = *i->second;
			if(cfgSetting){
				log("Value found in file for: " + i->first);
				defaultValue = cfgSetting;
			}else{
				log("Value NOT found in file for: " + i->first);
				cfgSetting = defaultValue;
			}
		}	
	}

	Json::config::Setting &Module::registerSetting(Json::config::Setting &e) const{
		_settings[e.name] = &e;
		return e;
	}

	void Module::log(std::string message, LogLevel lvl) const{
		Log(id, message, lvl);
	}

	std::vector<JAM::MODULE::Module *> &Module::_m(){
		return modules;
	}	
}


void Log(std::string module, std::string message, LogLevel lvl){
	std::ostringstream out;
	out << "\033";
	std::time_t tt =  std::chrono::system_clock::to_time_t ( std::chrono::system_clock::now());
	struct std::tm * ptm = std::localtime(&tt);

	if(lvl == INFO)		out << BLUE 	<< "[INFO]";
	if(lvl == ALERT)	out << YELLOW 	<< "[ALERT]";
	if(lvl == STATUS)	out << GREEN 	<< "[STATUS]";
	if(lvl == WARNING)	out << RED 		<< "[WARNING]";
	if(lvl == ACTION)	out << MAGENTA  << "[ACTION]";

	out << std::setw(10 - out.tellp()) << "[" << std::put_time(ptm, "%c") << "]";
	if(!module.empty()) out << "[" << module << "]" ;
	out << "\033[0m";
	std::cout << out.str() << std::setw(55 - out.tellp()) << ": " << message << std::endl;
}

ModuleMap &Modules(){	return modules;	}

void initModules(){
	Json::config::Config config("../data/config.json");
	for(ModuleMap::iterator i = modules.begin(); i != modules.end(); i++){
		(*i)->log("Config...", ACTION);
		(*i)->configure(config);
	}

	for(ModuleMap::iterator i = modules.begin(); i != modules.end(); i++){
		try{
			(*i)->log("Init", ACTION);
			(*i)->init();
		}catch(JAM::MODULE::JAMException &e){
			e.dispatch();
		}
	}
}