#ifndef JAM_CORE_HPP
#define JAM_CORE_HPP

#include "modules/module.hpp"
#include "jam/glfw/GlfwModule.hpp"
#include "jam/engine/JAMEngine.hpp"
#include "glm/glm.hpp"


namespace JAM::Core{
	class JAMCore : public JAM::MODULE::Module{
		public:
			GLFW::GLFWModule		glfw;
			Engine::JAMEngine		engine;

			JAMCore();
			bool init();
	};
}


#endif