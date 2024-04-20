#define TS_INCLUDE_UI
#include "../include/TS.h"
#include "../include/shader_templates.h"
#include "../include/menubar.h"


float prev_x = 0;
float prev_y = 0;
double size = -1;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (size > 1)
        size -= yoffset;
    else if (size <= 1 && size >= 0.1f)
        size -= yoffset/10;
    else if (size <= 0.1f)
        size -= yoffset/100;
}

void EditorInput(TS* t)
{
    auto& io = ImGui::GetIO();
    if (io.WantCaptureMouse || io.WantCaptureKeyboard) {
        return;
    }
    double mouseX, mouseY;
    glfwGetCursorPos(t->window, &mouseX, &mouseY);
    float worldX = 2 * (mouseX / t->width) - 1;
    float worldY = -2 * (mouseY / t->height) + 1;
    float mouseDeltaX = worldX - prev_x;
    float mouseDeltaY = worldY - prev_y;
    size = min((float)size, -0.01f);
    t->size = size;
    if (glfwGetMouseButton(t->window, 1))
    {
        t->x += mouseDeltaX * 2;
        t->y += mouseDeltaY;
    }
    prev_x = worldX;
    prev_y = worldY;
}

int main()
{
    TS t = TS(1920, 1080, "TS-GUI");
    t.size = -1;
    glfwSetScrollCallback(t.window, scroll_callback);
    CreateMenuBar(t.window);
    Sprites sprites;

    Shader shader = Shader((char*)vert_2D, (char*)frag_unlit);

    Texture texture = Texture("./Assets/Textures/test.png");
    Texture move = Texture("./Assets/UI/move.png");
    texture.SetTextureMode(TS_NEAREST);

    Sprite sprite = Sprite(&texture, &shader, "Sprite");
    sprites.sprites.push_back(sprite);

    Sprite moveS = Sprite(&move, &shader, "Move");
    sprites.sprites.push_back(moveS);

    UI ui = UI(t.window);

    ImGuiIO& io = ImGui::GetIO();
    ImFont* font = io.Fonts->AddFontFromFileTTF("./Assets/UI/default.ttf", 20);

	while (!glfwWindowShouldClose(t.window))
	{
        EditorInput(&t);

        t.Begin(0.2f, 0.3f, 1, 1);
        sprite.Begin(&t);
        sprite.Render(&t);

        ui.NewFrame();
        ImGui::PushFont(font);

        RenderEditor(&ui, &t, &sprites, &move);

        FpsCounter(&ui);

        ImGui::PopFont();
        ui.Render();
        t.End();
	}

    ui.Shutdown();
}