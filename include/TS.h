#pragma once
#ifdef TS_INCLUDE_UI
#include "../include/ui.h"
#include "../include/sprite.h"

void RenderEditor(UI* ui, TS* t, Sprites* s, Texture* tex)
{
	

	ImGui::SetNextWindowPos(ImVec2(0 + (t->width / 5), t->height - (t->height / 4)));
	ImGui::SetNextWindowSize(ImVec2(t->width - (t->width / 5) * 2, t->height + t->height/5));
	TEST_TAB(ui, "Files");

	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(t->width / 5, t->height));
	ui->CreateTab("Scene");

	for (int i = 0; i < s->sprites.size(); i++)
	{
		if (ImGui::Button(s->sprites[i].name))
		{
			s->current_sprite_selected = i;
		}
	}

	ui->EndTab();

	if (s->current_sprite_selected != -1)
	{
		ImGui::SetNextWindowPos(ImVec2(t->width - (t->width / 5), 0));
		ImGui::SetNextWindowSize(ImVec2(t->width / 5, t->height));
		ui->CreateTab("Inspector");
		static float vec4f[2] = { s->sprites[s->current_sprite_selected].x, s->sprites[s->current_sprite_selected].y };
		ImGui::InputFloat2("Position", vec4f);
		s->sprites[s->current_sprite_selected].x = vec4f[0];
		s->sprites[s->current_sprite_selected].y = vec4f[1];
		ui->EndTab();
	}
	ui->CreateTabMoveable("Tools");
	ImGui::Button("Move");
	ImGui::Button("Rotate");
	ImGui::Button("Scale");
	ui->EndTab();
}

double previousTime = glfwGetTime();
int frameCount = 0;
int c;

void FpsCounter(UI* x)
{
	double currentTime = glfwGetTime();									
	x->CreateTabMoveable("FPS");										
	if (currentTime - previousTime >= 1.0)								
	{																	
		c = frameCount;													
		frameCount = 0;													
		previousTime = currentTime;										
	}																	
	ImGui::Text("FPS : %i", c);										
	x->EndTab();
}

#else
#include "../include/sprite.h"
#endif
