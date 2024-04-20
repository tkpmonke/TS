#pragma once
#ifdef TS_INCLUDE_UI
#include "../include/ui.h"
#include "../include/sprite.h"

void RenderEditor(UI* ui, TS* t, Sprites* s, Texture* tex)
{
	ImGui::SetNextWindowPos(ImVec2(t->width - (t->width / 5), 0));
	ImGui::SetNextWindowSize(ImVec2(t->width / 5, t->height));
	TEST_TAB(ui, "Inspector");

	ImGui::SetNextWindowPos(ImVec2(0 + (t->width / 5), t->height - (t->height / 4)));
	ImGui::SetNextWindowSize(ImVec2(t->width - (t->width / 5) * 2, t->height + t->height/5));
	TEST_TAB(ui, "Files");

	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(t->width / 5, t->height));
	ui->CreateTab("Scene");

	for (Sprite s : s->sprites)
	{
		ImGui::Button(s.name);
	}

	ui->EndTab();

	ui->CreateTabMoveable("Tools");
	ImGui::Button("Move");
	ImGui::Button("Rotate");
	ImGui::Button("Scale");
	ui->EndTab();
}

#else
#include "../include/sprite.h"
#endif
