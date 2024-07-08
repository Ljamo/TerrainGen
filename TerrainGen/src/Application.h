#pragma once
#include "pch.h"
#include "Shader.h"
#include "ApplicationDispatcher.h"

class Application : public ApplicationDispatcher
{
public:

    Application(uint32_t width, uint32_t height, const std::string& title, const std::string& vertName, const std::string& fragName);
    bool Init();
    void Run();
    void CleanUp();

    // Shader* shader = nullptr;

    // GLfloat* m_Vertices = nullptr;
    // GLuint* m_Indices = nullptr;
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;

private:
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);

    GLFWwindow* window = nullptr;
    uint32_t m_Width, m_Height;
    std::string m_Title;

    // GLuint VAO, VBO, EBO;
    // GLuint shaderProgram;
};