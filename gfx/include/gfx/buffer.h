#pragma once
#include <glad/glad.h>

namespace LatticeViz::GFX
{
	enum class BufferType : GLenum {
		Vertex   = GL_ARRAY_BUFFER,
		Index    = GL_ELEMENT_ARRAY_BUFFER,
		Uniform  = GL_UNIFORM_BUFFER,
		Instance = GL_ARRAY_BUFFER
	};

	struct Buffer {
		GLuint id = 0;
		BufferType type;
		GLsizeiptr size = 0;
		GLenum usage = GL_STATIC_DRAW;

		static Buffer Create(BufferType type, GLsizeiptr size, const void* data = nullptr, GLenum usage = GL_STATIC_DRAW);
		void Update(GLintptr offset, GLsizeiptr dataSize, const void* data) const;
		void Bind() const;
		void Destroy();
	};
}
