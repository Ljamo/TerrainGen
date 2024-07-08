// ApplicationDispatcher.cpp
#include "ApplicationDispatcher.h"

void ApplicationDispatcher::InitGraphics(bool hasEBO, std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{
	HandleVertices(vertices);
	HandleIndices(indices);

	GetShaders();

	GenBaseBuffers(hasEBO, m_Vertices.data(), m_Vertices.size(), hasEBO ? m_Indices.data() : nullptr, hasEBO ? m_Indices.size() : 0);
}

void ApplicationDispatcher::OnUpdate()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	Use();
	OnUpdateBuffers();
}

void ApplicationDispatcher::DispatchCleanup()
{
	BufferCleanup();
}