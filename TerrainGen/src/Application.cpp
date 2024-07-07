#include "Application.h"

// Constructor definition
Application::Application(uint32_t width, uint32_t height, const std::string& title, const std::string shaderName)
    : m_Width(width), m_Height(height), m_Title(title), window(nullptr)
{
    vertexShaderPath = (parentDir + "\\TerrainGen\\src\\shaders\\" + shaderName + ".vert").c_str();
    fragmentShaderPath = (parentDir + "\\TerrainGen\\src\\shaders\\" + shaderName + ".frag").c_str();

    //Init();
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

    // Use vertex data from the vector
    if (!vertices.empty())
    {
        s_Vertices = vertices.data();
    }

    if (!indices.empty())
    {
        s_Indices = indices.data();
    }

    // Generate VBO and bind it
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Send vertices to GPU
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), s_Vertices, GL_STATIC_DRAW);

    // Generate VAO and bind it
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Link vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Create EBO and Bind
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), s_Indices, GL_STATIC_DRAW);

    // Unbind VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    shader = new Shader(vertexShaderPath, fragmentShaderPath);
    shader->Use();
    return true;
}


// Run method
void Application::Run()
{
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader->Use();

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

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

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    delete shader;

    if (window)
    {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}