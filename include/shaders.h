#pragma once

class Shader {
public:
	Shader(char* vert, char* frag);

	void SetValue(float f, const char* name);
	void SetValue(int i, const char* name);

	operator int() const { return program; }

private:
	unsigned int program;
};
