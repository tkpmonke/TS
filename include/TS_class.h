#pragma once

#define GLEW_STATIC
#include "../libs/include/glew.h"
#include "../libs/include/glfw3.h"
#include "../include/shaders.h"

enum RenderState {
	RS_SOLID = 0x1B02,
	RS_WIREFRAME = 0x1B01
};

class TS {
public:
	GLFWwindow* window;
	int width, height;

	TS(int width, int height, const char* name);

	void SetRenderState(RenderState s);

private:
	void InitOpenGL();
};