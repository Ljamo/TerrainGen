// VertexData.h
#pragma once
#include "pch.h"

class VertexData
{
public:
    VertexData() { std::cout << "VertexData Initialized" << std::endl; }

    void HandleVertices(std::vector<GLfloat>& vertices);
    void HandleIndices(std::vector<GLuint>& indices);

protected:
    std::vector<GLfloat> m_Vertices;
    std::vector<GLuint> m_Indices;

private:
    uint32_t GetElementSize();
};
