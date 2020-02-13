#ifndef JAM_GLOBJECT_HPP
#define JAM_GLOBJECT_HPP

#include "modules/resource.hpp"
#include "glad/glad.h"

namespace JAM::Engine::GL {

	typedef void(*gl_gen_portal)(GLsizei , GLuint *); // Amount to be gened and return pointer
	typedef void(*gl_del_portal)(GLsizei, const GLuint *); // Amount and who to delete
	typedef void (*gl_bind_portal)(GLenum, GLuint); // Targeted binding and render target

	enum GLObjectType{
		Buffer, Texture, Framebuffer, Sampler, VertexArray, RenderBuffer, Query, Pipeline, TransformFeedback
	};

	class GLObject : public JAM::MODULE::Resource{
		public:
			GLObject(GLObjectType t, GLenum target, GLsizei size);

			bool create() const;
			bool bind() const;

			~GLObject();

		private:
			struct ObjectManager{
				const gl_gen_portal  gen;
				const gl_del_portal   del;
				const gl_bind_portal bind;
			};
			ObjectManager genManager(GLObjectType const t);

			const GLenum 				  target;
			const ObjectManager 	  manager;
			const GLsizei					size;
			mutable GLuint				allocation;

	};
};

#endif