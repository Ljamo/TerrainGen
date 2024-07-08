//Buffers.h
#pragma once
#include "pch.h"
#include "shader.h"

class Buffers : public Shader
{
public:
    Buffers(const std::string& vertexPath, const std::string& fragmentPath);
    ~Buffers() {};

    void DeleteBuffers();

    void GenBaseBuffers(bool hasEBO, GLfloat* vertices, size_t vertexCount, GLuint* indices, size_t indexCount);

    void OnUpdateBuffers();
    void BufferCleanup();

private:
    GLuint VBO, VAO, EBO;
    GLuint shaderProgram;
};