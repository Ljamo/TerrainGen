#include "pch.h"
#include "Application.h"

// Settings
const unsigned int width = 800;
const unsigned int height = 600;
const std::string title = "Test Window";
const std::string shaderName = "default";

std::vector<GLfloat> vertices = {
    -0.5f, -0.5f, 0.0f, // Lower left corner
     0.5f, -0.5f, 0.0f, // Lower right corner
     0.0f,  0.5f, 0.0f  // Upper corner
};

int main() {
    Application* app = new Application(width, height, title, shaderName);

    // Initial vertices setup
    app->vertices.insert(app->vertices.end(), std::begin(vertices), std::end(vertices));

    if (!app->Init()) {
        delete app;
        return -1;
    }

    // Update vertices if needed
    // app->vertices.push_back(0.5f);
    // app->vertices.push_back(0.5f);
    // app->vertices.push_back(0.0f);
    app->UpdateVertices();

    app->Run();
    delete app;

    return 0;
}
