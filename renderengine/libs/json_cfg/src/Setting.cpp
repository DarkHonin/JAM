#include "jsoncfg/jsonconfig.hpp"

namespace Json::config{
	Setting::Setting(std::string const &name) : Json::Value(), name(name), onChange(NULL){}

	Setting::Setting(std::string const &name, Json::Value const &clone, void(*fn)(Setting &)) : name(name), Json::Value(clone), onChange(fn){}
	Setting &Setting::operator=(Setting const &e){
		Json::Value::operator=((Json::Value)e);
		if(onChange) onChange(*this);
		return *this;
	}
}