#include "jam/glfw/GlfwModule.hpp"
#include "modules/exception.hpp"

namespace JAM::GLFW{
	GLFWModule::GLFWModule() : Module("GLFW"){
		_resolution = glm::ivec2(400);
		_fullscreen = false;
		registerSetting(_resolution);
		registerSetting(_fullscreen);

	}

	bool GLFWModule::init(){
		if(glfwInit() == GLFW_FALSE) throw MODULE::ModuleException(*this, "Could not init glfw");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);					//
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);					// OpenGl 3.3
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// Spespicy core profile

		glfwSwapInterval(1);											// 1 frame = really tiny amount of time.

		log("Opening window...", ALERT);
		_window = new Window(_resolution,  (bool &)_fullscreen);
		if(!_window)throw MODULE::ModuleException(*this, "Could not open window");
		log("Window is open");


		registerResource("window", _window); // "Resource registry MUST be after init"

		return true;
	}

	ResoluionSetting &ResoluionSetting::operator=(glm::ivec2 const &in){
		(*this)[0] = in.x;
		(*this)[1] = in.y;
		return *this;
	}

	FullscreenSetting &FullscreenSetting::operator=(bool const &in){
		Json::Value::operator=(in);
		return *this;
	}

	ResoluionSetting::ResoluionSetting() : Setting("Resolution"){}

	FullscreenSetting::FullscreenSetting() : Setting("Fullscreen"){}


	
}