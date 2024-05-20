#pragma once
#include "pch.h"

class Application
{
public:
    Application(uint32_t width, uint32_t height, const std::string& title);
    bool Init();
    void Run();
    void CleanUp();

private:
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);

    GLFWwindow* window = nullptr;
    uint32_t m_Width, m_Height;
    std::string m_Title;

    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
        "}\0";

    GLuint VAO, VBO;
    GLuint shaderProgram;
};