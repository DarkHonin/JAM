#include "jsoncfg/jsonconfig.hpp"
#include <iostream>
Json::Value & operator>>(Json::Value &v, int *dat){
	*dat = v.asInt();
	return v;
}

Json::Value & operator>>(Json::Value &v, bool *dat){
	*dat = v.asBool();
	return v;
}

int main(){
	Json::config::init("test0.json");
	Json::config::config().config<int>("index", 11);
	Json::config::config().config<bool>("fullscreen", true);

	return 0;
}