#include "pch.h"

#include "Application.h"


//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const unsigned int width = 800;
const unsigned int height = 600;
const std::string title = "Test Window";

const std::string shaderName = "default";

GLfloat vertices[] =
{
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
};

int main()
{
    Application* app = new Application(width, height, title, shaderName);
    app->vertices.insert(app->vertices.end(), std::begin(vertices), std::end(vertices));
    app->Init();
    app->Run();
    //app->CleanUp();
    delete app;
    return 0;
}