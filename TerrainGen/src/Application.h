#pragma once
#include "pch.h"

class Application
{
public:
	Application(uint32_t width, uint32_t height, const std::string& title);
	bool Init();
	void Run();
	void CleanUp();
private:
	static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow* window);

	GLFWwindow* window = nullptr;

	uint32_t m_Width, m_Height;
	std::string m_Title = nullptr;
};

