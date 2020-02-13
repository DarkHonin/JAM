#include "jam/core/JAMCore.hpp"
#include "jam/glfw/GlfwModule.hpp"
#include "jam/engine/JAMEngine.hpp"
#include "jam/engine/gl/glObject.hpp"

int main(){
	JAM::Core::JAMCore core;
	initModules();
	JAM::Engine::GL::GLObject o(JAM::Engine::GL::GLObjectType::Buffer, GL_ARRAY_BUFFER, 1);
	o.bind();
	while(1){}
}