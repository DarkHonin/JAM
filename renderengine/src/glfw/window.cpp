#include "jam/glfw/window.hpp"
#include <iostream>

namespace JAM::GLFW{
	Window::Window(glm::ivec2 &resolution, bool &fullscreen) :
		resolution(resolution), fullscreen(fullscreen), window(glfwCreateWindow(resolution.x, resolution.y, "JAM", (fullscreen ? glfwGetPrimaryMonitor() : 0), 0)){}

	Window::~Window(){
		delete &resolution;
	}

	Window::operator bool(){
		return window;
	}

	Window::operator GLFWwindow *(){
		return window;
	}

}