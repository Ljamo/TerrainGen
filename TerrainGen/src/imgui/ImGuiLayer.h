#pragma once
#include "../pch.h"

class ImGuiLayer
{
public:
	void OnAttach();
	void OnDetach();
	void OnImGuiRender();

	void Begin();
	void End();
};

