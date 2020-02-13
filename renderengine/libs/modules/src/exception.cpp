#include "modules/exception.hpp"

namespace JAM::MODULE{
	JAMException::JAMException(std::string const message, int const severity) : std::runtime_error(message), severity(severity){}

	void JAMException::dispatch(){
		Log(NULL, what(), WARNING);
	}


	ModuleException::ModuleException(Module const &module, std::string const message) : JAMException(message, module.index), module(module){}

	void ModuleException::dispatch(){
		module.log(what(), WARNING);
	}
}