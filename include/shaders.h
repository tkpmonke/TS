#pragma once
#include "../libs/include/glm/glm.hpp"
#include "../libs/include/glm/gtc/matrix_transform.hpp"
#include "../libs/include/glm/gtc/type_ptr.hpp"

class Shader {
public:
	Shader(char* vert, char* frag);

	void SetValue(float f, const char* name);
	void SetValue(int i, const char* name);
	void SetValue(glm::mat4 m, const char* name);

	unsigned int program;
	operator int() const { return program; }

};
