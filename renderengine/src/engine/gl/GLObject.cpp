#include "jam/engine/gl/glObject.hpp"
#include "modules/exception.hpp"

namespace JAM::Engine::GL{

	bool checkGLException(){
		if(GLenum error = glGetError()){
			throw MODULE::JAMException("Could not preform opperation reason: "+std::to_string(error), 2);
			return false;
		}
		return true;
	}

	GLObject::ObjectManager GLObject::genManager(GLObjectType const t){
		switch(t){
			case Buffer:
				return {glGenBuffers,
							glDeleteBuffers,
							glBindBuffer};
			case Texture:
				return {glGenTextures,
							glDeleteTextures,
							glBindTexture};
			case Framebuffer:
				return {glGenFramebuffers,
							glDeleteFramebuffers,
							glBindFramebuffer};
			default:
				throw MODULE::JAMException("Invalid object type enum: "+std::to_string(t), 2);
		}
	}

	GLObject::GLObject(GLObjectType t, GLenum target, GLsizei size) :
		target(target), size(size), manager(genManager(t)), allocation(-1)
	{}

	bool GLObject::create() const{
		manager.gen(size, &allocation);
		return checkGLException();
	}

	bool GLObject::bind() const{
		if(allocation == -1) create();
		manager.bind(target, allocation);
		return checkGLException();
	}


	GLObject::~GLObject(){
		manager.del(size, &allocation);
		checkGLException();
	}

}