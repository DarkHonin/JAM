#ifndef JSON_CFG_CPP
#define JSON_CFG_CPP

#include <string>
#include <fstream>
#include <iostream>
#include "json/json.h"
#include <map>
#define _l << "JSONCONFIG::INIT::" <<
namespace Json::config{

	

	/*
		The Setting struct serves as a universal interface
		for all settings.
		
		To add more complex datatypes add the correct
			Setting &opperator=(<type>)
		to an ingeriting type
	*/
	struct Setting : public Json::Value{
		const std::string name;
		void(*onChange)(Setting &);
		
		Setting(std::string const &name);
		Setting(std::string const &name, Json::Value const &clone, void(*fn)(Setting &));
		Setting &operator=(Setting const &e);
	};
	/*
		The Config class serves as the manager for the configuration
		json file.

		Mostly reading from/ writing to the json file.
		in addition to that it supports custom objects
		through '>>' operator overloads.

		Json::Value &operator>>(Json::Value &in, <type> *out);
	*/
	
	class Config : public Json::Value{
		public:
			const std::string path;
			Config(std::string path);
			Setting &operator[](std::string const &key);
		private:
			void save();
			void load();
	};


	void init(std::string const &path);
	Config &config();

	typedef Setting setting;
	typedef std::map<std::string, setting *> SettingMap;
}


#endif