#pragma once
#define IMGUI_IMPL_OPENGL_LOADER_GLEW
#include "../libs/include/ImGUI/imgui.h"
#include "../libs/include/ImGUI/imgui_impl_glfw.h"
#include "../libs/include/ImGUI/imgui_impl_opengl3.h"

#define CENTER_WINDOW() ImVec2 center = ImGui::GetMainViewport()->GetCenter();						\
						ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

#define TEST_TAB(x, g)		x->CreateTab(g);										\
						ImGui::Button("Button??? is this working???");			\
						x->EndTab();


class UI {
public:
	UI(GLFWwindow* t);

	void NewFrame();

	void CreateTab(const char* name);

	void CreateTabMoveable(const char* name);

	void EndTab();

	void Render();

	void Shutdown();

};

