#pragma once
#include "../include/TS_class.h"

class Texture {
public:
	char* location;
	unsigned char* data;
	int width, height, channels;
	int texMode = TS_LINEAR;
	unsigned int glLocation;

	Texture(char* location);
	void SetTextureMode(int texMode) { this->texMode = texMode; }

	operator unsigned char* () const { return data; }
	operator unsigned int () const { return glLocation; }
};


class Sprite {
public:
	float x, y, z;
	float scale_x = 1, scale_y = 1, scale_z = 1;
	Shader* shader;
	Texture* tex;
	char* name;
	
	Sprite(Texture* t, Shader* s, char* name)
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;

		CreateVertexBuffer();

		CreateTexture(t);

		this->shader = s;
		this->tex = t;
		this->name = name;
	}

	void Begin(TS* t);
	void Render(TS* t);

		
private:
	void CreateVertexBuffer();
	void CreateTexture(Texture* t);
	unsigned int vao;
};

class Sprites {
public:
	std::vector<Sprite> sprites;
	operator std::vector<Sprite>() const { return sprites; }
};