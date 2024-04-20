#pragma once
#include <vector>
#include "../include/defines.h"
#include "../libs/include/glew.h"
#include "../libs/include/glfw3.h"

#include "../include/shaders.h"

class TS {
public:
	GLFWwindow* window;
	int width, height;
	float x, y;
	float size;

	TS(int width, int height, const char* name);

	void SetRenderState(int s);

	void Begin(float r, float g, float b, float a);

	void End();
private:
	void InitOpenGL();
};