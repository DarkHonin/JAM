#ifndef JAM_WINDOW_HPP
#define JAM_WINDOW_HPP

#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "modules/module.hpp"

namespace JAM::GLFW{
	class Window : public MODULE::Resource{
		private:
			glm::ivec2 &resolution;
			bool	   &fullscreen;
			GLFWwindow *window;
		public:
			Window(glm::ivec2 &resolution, bool &fullscreen);
			~Window();

			operator bool();

			operator GLFWwindow *();
	};
}

#endif