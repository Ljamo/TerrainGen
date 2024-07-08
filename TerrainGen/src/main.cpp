// Main.cpp
#include "pch.h"

#include "Application.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const unsigned int width = 800;
const unsigned int height = 600;
const std::string title = "Test Window";

const std::string shaderName = "default";

const std::string vertName = (parentDir + "\\TerrainGen\\src\\shaders\\" + shaderName + ".vert").c_str();
const std::string fragName = (parentDir + "\\TerrainGen\\src\\shaders\\" + shaderName + ".frag").c_str();

/*
GLfloat vertices[] =
{
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
};
*/

GLfloat vertices[] = {
    0.5f, 0.5f, 0.0f, // top right
    0.5f,-0.5f, 0.0f, // bottom right
    -0.5f,-0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f // top left
};

GLuint indices[] = { // note that we start from 0!
0, 1, 3, // first triangle
1, 2, 3 // second triangle
};

int main()
{
    Application* app = new Application(width, height, title, vertName, fragName);
    app->vertices.insert(app->vertices.end(), std::begin(vertices), std::end(vertices));
    app->indices.insert(app->indices.end(), std::begin(indices), std::end(indices));
    app->Init();
    app->Run();
    //app->CleanUp();
    delete app;
    return 0;
}