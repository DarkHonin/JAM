#ifndef JAM_MODULE_HPP
#define JAM_MODULE_HPP

#include <string>
#include "jsoncfg/jsonconfig.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include "resource.hpp"

enum LogLevel{
	INFO,
	ALERT,
	STATUS,
	WARNING,
	ACTION
};

void Log(std::string module, std::string message, LogLevel lvl = STATUS);



void initModules();

namespace JAM::MODULE{



	/*
		A module provides a universal intrface for
		managing the diffarent aspects at play.

		Primairy features include:
			~ A logging interface
			~ Log message prefixing
			~ Resource sharing
			~ Directed error messages
	*/


	class Module : public ResourceContainer{
		public:
			const std::string 	id;
			const int			index;

			Module(std::string id);
			void configure(Json::config::Config &cfg);
			virtual bool init() = 0;
			Json::config::Setting &registerSetting(Json::config::Setting &e) const;
			void log(std::string message, LogLevel lvl=STATUS) const;

			template<typename t>
			t *rsu(int module, std::string resource){
				return(t *) (*(_m()[module]))[resource];
			}

		private:
			mutable Json::config::SettingMap	_settings; //Settings
			std::vector<JAM::MODULE::Module *> &_m();
			// Assets/Resources
	};
}


typedef std::vector<JAM::MODULE::Module *> ModuleMap;

ModuleMap &Modules();


#endif