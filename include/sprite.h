#pragma once
#include "../include/TS_class.h"

class Texture {
public:
	  char* location;
			int glLocation;
			// Load Texture is not implemented yet
			// operator char*() const { return LoadTexure(location) }
};

class Sprite {
public:
		float x, y, z;
  
		Sprite()
		{
					
		}
		
private:
	 void CreateVertexBuffer();
};