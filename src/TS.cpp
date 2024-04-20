#include "../include/TS_class.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
    
}

TS::TS(int width, int height, const char* name)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	this->window = glfwCreateWindow(width, height, name, NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, framebuffer_size_callback);

	InitOpenGL();
}

void TS::InitOpenGL()
{
	glewExperimental = true;
	glewInit();
	glEnable(GL_DEPTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void TS::Begin(float r, float g, float b, float a)
{
    glClearColor(0, 0.2f, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int width, height;
    glfwGetWindowSize(window, &width, &height);
    this->width = width;
    this->height = height;
}

void TS::End()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void TS::SetRenderState(int s)
{
    glPolygonMode(GL_FRONT_AND_BACK, s);
}

void Shader::SetValue(float f, const char* name)
{
	glUniform1f(glGetUniformLocation(this->program, name), f);
}

void Shader::SetValue(int i, const char* name)
{
	glUniform1i(glGetUniformLocation(this->program, name), i);

}
void Shader::SetValue(glm::mat4 m, const char* name)
{
    glUniformMatrix4fv(glGetUniformLocation(this->program, name), 1, GL_FALSE, &m[0][0]);

}

Shader::Shader(char* vert, char* frag)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vert, NULL);
    glCompileShader(vertexShader);

#ifdef DEBUG
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        TS_ERROR_CODE(infoLog, 100);
    }
#endif

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &frag, NULL);
    glCompileShader(fragmentShader);

#ifdef DEBUG
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        TS_ERROR_CODE(infoLog, 101);
    }
#endif

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

#ifdef DEBUG
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        TS_ERROR_CODE(infoLog, 102);
    }
#endif

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    this->program = shaderProgram;
}
