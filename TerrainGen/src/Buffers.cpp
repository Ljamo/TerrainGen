//Buffers.cpp
#include "Buffers.h"

Buffers::Buffers(const std::string& vertexPath, const std::string& fragmentPath)
    : Shader(vertexPath, fragmentPath)
{
    std::cout << "Buffers Initialized " << std::endl;
}

void Buffers::DeleteBuffers()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
}

void Buffers::GenBaseBuffers(bool hasEBO, GLfloat* vertices, size_t vertexCount, GLuint* indices, size_t indexCount)
{
    // Generate and bind VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    // Link vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    if (hasEBO && indices != nullptr)
    {
        // Generate and bind EBO
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(GLuint), indices, GL_STATIC_DRAW);
    }

    // Unbind VAO to prevent accidental modification
    glBindVertexArray(0);

    // Optional: Unbind VBO and EBO (they remain bound to the VAO)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    if (hasEBO && indices != nullptr)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    Use(); // Shader's usage
}

void Buffers::OnUpdateDraw()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Buffers::BufferCleanup()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
}