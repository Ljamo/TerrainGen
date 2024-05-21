#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class Application {
public:
    Application(uint32_t width, uint32_t height, const std::string& title, const std::string& shaderName);
    bool Init();
    void Run();
    void CleanUp();
    void UpdateVertices();
    void updateProjectionMatrix();

    Shader* shader = nullptr;
    std::vector<GLfloat> vertices;

private:
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);

    GLFWwindow* window = nullptr;
    uint32_t m_Width, m_Height;
    std::string m_Title;
    std::string vertexShaderPath;
    std::string fragmentShaderPath;

    GLuint VAO, VBO;
};
