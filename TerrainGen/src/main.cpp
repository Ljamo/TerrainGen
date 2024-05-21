#include "pch.h"

#include "Application.h"


//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const unsigned int width = 800;
const unsigned int height = 600;
const std::string title = "Test Window";

const std::string shaderName = "default";

int main()
{
    Application* app = new Application(width, height, title, shaderName);
   // app->Init();
    app->Run();
    //app->CleanUp();
    delete app;
    return 0;
}