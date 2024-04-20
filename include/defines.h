#pragma once
#include <iostream>

// LIBRARYS
#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION

// CONSOLE MANAGEMENT
#define TS_PRINT(x) std::cout << x << "\n"; 
#define TS_ERROR(x) std::cout << "TS : ERROR : " << x << "\n";
#define TS_ERROR_CODE(x, c) std::cout << "TS : ERROR : " << x << " : ERROR CODE : " << c;

// RENDERSTATES
#define TS_WIREFRAME		0x1B01
#define TS_SOLID			0x1B02

// TEXTURE MODE
#define TS_LINEAR			0x2601
#define TS_NEAREST			0x2600