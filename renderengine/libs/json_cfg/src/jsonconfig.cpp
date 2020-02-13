#include "jsoncfg/jsonconfig.hpp"
#include <iostream>


namespace Json::config{

	Config *configInstance;

	void init(std::string const &path){
		std::cout _l "Starting up" << std::endl;
		
		configInstance = new Config(path);

		std::cout _l "OK" << std::endl;
	}

	Config::Config(std::string path) : path(path){ load(); }

	void Config::save(){
		std::ofstream ostream(path);
		ostream << *this;
	}

	void Config::load(){
		std::fstream instream(path);
		try{
			instream >> *this;

		} catch (Json::RuntimeError &e){
			std::cout _l "Could not load file: " << path << std::endl;
		}
		instream.close();
	}

	Setting &Config::operator[](std::string const &key){
		Json::Value &ret = Json::Value::operator[](key);
		static Config &self = * static_cast<Config *>(this);
		auto _save = [](Setting &e){
			std::cout _l "Saving config: " << e.name << std::endl;
			((Json::Value &) self)[e.name] = e;
			self.save();
		};
		return *new Setting(key, ret, _save);
	}

	Config &config(){
		return *configInstance;
	}
}