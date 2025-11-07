#include <gfx/shader.h>
#include <iostream>

#include "glm/gtc/type_ptr.hpp"

namespace LatticeViz::GFX
{
    GLuint Shader::CompileShader(GLenum type, const char* src)
    {
        GLuint shaderId = glCreateShader(type);
        glShaderSource(shaderId, 1, &src, nullptr);
        glCompileShader(shaderId);

        GLint success;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char infoLog[1024];
            glGetShaderInfoLog(shaderId, 1024, nullptr, infoLog);
            std::cerr << "[Shader Compilation Error] "
                << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment")
                << ":\n" << infoLog << std::endl;
            glDeleteShader(shaderId);
            assert(false && "Shader compilation failed");
        }

        return shaderId;
    }

    Shader Shader::Create(const char* vertexSrc, const char* fragmentSrc)
    {
        Shader shader;

        GLuint vert = CompileShader(GL_VERTEX_SHADER, vertexSrc);
        GLuint frag = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

        shader.id = glCreateProgram();
        glAttachShader(shader.id, vert);
        glAttachShader(shader.id, frag);
        glLinkProgram(shader.id);

        GLint success = 0;
        glGetProgramiv(shader.id, GL_LINK_STATUS, &success);
        if (!success)
        {
            char infoLog[1024];
            glGetProgramInfoLog(shader.id, 1024, nullptr, infoLog);
            std::cerr << "[Shader Linking Error]:\n" << infoLog << std::endl;
            glDeleteProgram(shader.id);
            shader.id = 0;
            assert(false && "Shader program linking failed");
        }

        glDetachShader(shader.id, vert);
        glDetachShader(shader.id, frag);
        glDeleteShader(vert);
        glDeleteShader(frag);

        return shader;
    }

    void Shader::Bind() const
    {
        glUseProgram(id);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    void Shader::Destroy()
    {
        if (id)
        {
            glDeleteProgram(id);
            id = 0;
        }
    }

    GLint Shader::GetUniformLocation(const std::string& name) const
    {
        GLint loc = glGetUniformLocation(id, name.c_str());
        if (loc == -1)
            std::cerr << "[Shader Warning] Uniform '" << name << "' not found." << std::endl;
        return loc;
    }

    void Shader::SetUniformMat4(const std::string& name, const glm::mat4& value) const
    {
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void Shader::SetUniform1i(const std::string& name, int value) const
    {
        glUniform1i(GetUniformLocation(name), value);
    }

    void Shader::SetUniform1f(const std::string& name, float value) const
    {
        glUniform1f(GetUniformLocation(name), value);
    }

    void Shader::SetUniform3f(const std::string& name, const glm::vec3& value) const
    {
        glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(value));
    }
}
