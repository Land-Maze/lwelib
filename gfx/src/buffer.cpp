#include <gfx/buffer.h>

namespace LatticeViz::GFX
{
	Buffer Buffer::Create(BufferType type, GLsizeiptr size, const void* data, GLenum usage) {
		Buffer buf;
		buf.type = type;
		buf.size = size;
		buf.usage = usage;

		glGenBuffers(1, &buf.id);
		glBindBuffer(static_cast<GLenum>(type), buf.id);
		glBufferData(static_cast<GLenum>(type), size, data, usage);
		glBindBuffer(static_cast<GLenum>(type), 0);
		return buf;
	}

	void Buffer::Update(GLintptr offset, GLsizeiptr dataSize, const void* data) const {
		glBindBuffer(static_cast<GLenum>(type), id);
		glBufferSubData(static_cast<GLenum>(type), offset, dataSize, data);
		glBindBuffer(static_cast<GLenum>(type), 0);
	}

	void Buffer::Bind() const {
		glBindBuffer(static_cast<GLenum>(type), id);
	}

	void Buffer::Destroy() {
		if (id) glDeleteBuffers(1, &id);
	}
}
