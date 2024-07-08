// ApplicationDispatcher.h
#pragma once
#include "pch.h"
#include "Buffers.h"
#include "VertexData.h"

class ApplicationDispatcher : public Buffers, public VertexData
{
public:
    ApplicationDispatcher(const std::string& vertexPath, const std::string& fragmentPath)
        : Buffers(vertexPath, fragmentPath), VertexData() {}

    void InitGraphics(GLFWwindow* window, bool hasEBO, std::vector<GLfloat>& vertices, std::vector<GLuint>& indices);

    void AppDispatchOnUpdate();
    void DispatchCleanup();

private:
    GLFWwindow* m_Window = nullptr;
    // ImGuiIO* io = nullptr;
};

