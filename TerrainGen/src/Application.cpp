#include "Application.h"

// Constructor definition
Application::Application(uint32_t width, uint32_t height, const std::string& title, const std::string& vertName, const std::string& fragName)
    : m_Width(width), m_Height(height), m_Title(title), window(nullptr), ApplicationDispatcher(vertName, fragName)
{

}

// Framebuffer size callback definition
void Application::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Initialization method
bool Application::Init()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    glViewport(0, 0, m_Width, m_Height);

    InitGraphics(true, vertices, indices);
    
    return true;
}


// Run method
void Application::Run()
{
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        OnUpdate();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    CleanUp();
}

// Input processing method
void Application::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Cleanup method
void Application::CleanUp()
{
    std::cout << "Cleaning Up" << std::endl;

    DispatchCleanup();

    if (window)
    {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}