#pragma once
#include "pch.h"

class Shader
{
public:
	// Name of the program being used
	uint32_t ID;

	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	void GetShaders();

	void Use();
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
private:
	std::string m_VertexPath;
	std::string m_FragmentPath;
};

