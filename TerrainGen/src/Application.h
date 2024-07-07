#pragma once
#include "pch.h"
#include "Shader.h"

class Application
{
public:

    Application(uint32_t width, uint32_t height, const std::string& title, const std::string shaderName);
    bool Init();
    void Run();
    void CleanUp();

    Shader* shader = nullptr;

    GLfloat* s_Vertices = nullptr;
    GLuint* s_Indices = nullptr;
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;

    std::string vertexShaderPath = "";
    std::string fragmentShaderPath = "";
private:
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);


    GLFWwindow* window = nullptr;
    uint32_t m_Width, m_Height;
    std::string m_Title;

    GLuint VAO, VBO, EBO;
    GLuint shaderProgram;
};