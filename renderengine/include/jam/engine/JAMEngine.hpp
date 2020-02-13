#ifndef JAM_ENGINE_HPP
#define JAM_ENGINE_HPP

#include "modules/module.hpp"

/*
	The engine module will be responsible for wrangling all opengl activities and recources
*/

namespace JAM::Engine{
	class JAMEngine : public MODULE::Module{
		public:
			JAMEngine();
			bool init();
		private:
			
	};
};

#endif