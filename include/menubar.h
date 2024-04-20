#pragma once

#include <windows.h>

#define MENU_FILE 100
#define MENU_FILE_NEW 101
#define MENU_FILE_OPEN 102
#define MENU_FILE_SAVE 103
#define MENU_FILE_EXIT 104

#include "../libs/include/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "../libs/include/glfw3native.h"

void CreateMenuBar(GLFWwindow* win)
{
	HMENU hMenu = CreateMenu();

	AppendMenu(hMenu, MF_POPUP, MENU_FILE, L"File");
	AppendMenu(hMenu, MF_STRING, MENU_FILE_NEW, L"New");
	AppendMenu(hMenu, MF_STRING, MENU_FILE_OPEN, L"Save");
	AppendMenu(hMenu, MF_STRING, MENU_FILE_SAVE, L"Load");
	AppendMenu(hMenu, MF_STRING, MENU_FILE_EXIT, L"Exit");

	HWND hWnd = glfwGetWin32Window(win);

	SetMenu(hWnd, hMenu);
}