#ifndef JAM_EXCEPTION_HPP
#define JAM_EXCEPTION_HPP

#include "module.hpp"
#include <exception>
#include <string>

namespace JAM::MODULE{

	class JAMException : public std::runtime_error{
		public:
			const int severity;
			JAMException(std::string const message, int const severity);
			virtual void dispatch();
	};

	struct ModuleException : public JAMException{
		const Module &module;
		ModuleException(Module const &module, std::string const message);
		void dispatch();
	};
}

#endif