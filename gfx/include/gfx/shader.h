#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>

namespace LatticeViz::GFX
{
    struct Shader
    {
        static Shader Create(const char* vertexSrc, const char* fragmentSrc);

        void Bind() const;
        void Unbind() const;

        void SetUniformMat4(const std::string& name, const glm::mat4& value) const;
        void SetUniform1i(const std::string& name, int value) const;
        void SetUniform1f(const std::string& name, float value) const;
        void SetUniform3f(const std::string& name, const glm::vec3& value) const;

        void Destroy();

        GLuint ID() const { return id; }

    private:
        GLuint id = 0;

        static GLuint CompileShader(GLenum type, const char* src);
        GLint GetUniformLocation(const std::string& name) const;
    };
}
