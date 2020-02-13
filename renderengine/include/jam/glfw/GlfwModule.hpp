#ifndef JAM_GLFW_HPP
#define JAM_GLFW_HPP

#include "glad/glad.h"
#include "modules/module.hpp"
#include "glm/glm.hpp"
#include "window.hpp"

namespace JAM::GLFW{

	struct ResoluionSetting : public Json::config::Setting{
		ResoluionSetting();
		ResoluionSetting &operator=(glm::ivec2 const &in);

		operator glm::ivec2&(){
			return *new glm::ivec2(
				(*this)[0].asInt(),
				(*this)[1].asInt()
			);
		}
	};
	
	struct FullscreenSetting : public Json::config::Setting{
		FullscreenSetting();
		FullscreenSetting &operator=(bool const &in);
		operator bool(){
			return asBool();
		}
	};

	class GLFWModule : public JAM::MODULE::Module{
		public:
			GLFWModule();
			void configure(Json::config::Config &cfg);
			bool init();
		private:
			Window 					*_window;

			ResoluionSetting		_resolution;
			FullscreenSetting		_fullscreen;
			
	};
}

#endif