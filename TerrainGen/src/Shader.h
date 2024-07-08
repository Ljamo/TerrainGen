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

	void SetVec2(const std::string& name, glm::vec2 value) const;
	void SetVec3(const std::string& name, glm::vec3 value) const;
	void SetVec4(const std::string& name, glm::vec4 value) const;

	void SetMat3(const std::string& name, const glm::mat3& mat) const;
	void SetMat4(const std::string& name, const glm::mat4& mat) const;
private:
	std::string m_VertexPath;
	std::string m_FragmentPath;
};

