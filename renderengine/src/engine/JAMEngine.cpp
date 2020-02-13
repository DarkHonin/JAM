#include "jam/engine/JAMEngine.hpp"
#include "modules/exception.hpp"
#include "jam/glfw/GlfwModule.hpp"
namespace JAM::Engine{
	JAMEngine::JAMEngine() : MODULE::Module("Engine"){}

	bool JAMEngine::init(){
		GLFW::Window *window = rsu<GLFW::Window>(1, "window");	// Gets the window resource
		glfwMakeContextCurrent(*window);	// Grabbing context
		log("GL init...", ALERT);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) throw MODULE::ModuleException(*this, "Could not init GL");	// Big fancy exception
		log("GL init ok");
		return true;
	}
}