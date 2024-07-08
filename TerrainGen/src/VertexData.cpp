// VertexData.cpp
#include "VertexData.h"

void VertexData::HandleVertices(std::vector<GLfloat>& vertices)
{
    if (!vertices.empty())
    {
        m_Vertices = vertices;
    }
}

void VertexData::HandleIndices(std::vector<GLuint>& indices)
{
    if (!indices.empty())
    {
        m_Indices = indices;
    }
}