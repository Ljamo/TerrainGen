// ApplicationDispatcher.cpp
#include "ApplicationDispatcher.h"

void ApplicationDispatcher::InitGraphics(GLFWwindow* window, bool hasEBO, std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	m_Window = window;

	HandleVertices(vertices);
	HandleIndices(indices);

	GetShaders();

	GenBaseBuffers(hasEBO, m_Vertices.data(), m_Vertices.size(), hasEBO ? m_Indices.data() : nullptr, hasEBO ? m_Indices.size() : 0);

	// Generate ImguiApp later on
	if (AppDebug)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
		ImGui_ImplOpenGL3_Init();
	}
}

void ApplicationDispatcher::AppDispatchOnUpdate()
{
	// ImGui shit here
	if (AppDebug)
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Test");
		ImGui::Text("Text!");
		if (ImGui::Button("Save"))
			std::cout << "Saved" << std::endl;
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(m_Window);
        }
    }

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	float blueValue = (cos(timeValue) / 2.0f) + 0.5f;
	float redValue = (tan(timeValue) / 2.0f) + 0.5f;

	SetVec4("ourColor", glm::vec4(blueValue, greenValue, redValue, 1.0f));
	
	Use();
	OnUpdateDraw();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ApplicationDispatcher::DispatchCleanup()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	BufferCleanup();
}