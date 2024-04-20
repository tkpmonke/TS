#pragma once


const char* vert_2D =
"#version 430 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoords;\n"
"out vec2 texCoords;\n"
"uniform mat4 transform;\n"
"uniform mat4 projection;\n"
"uniform mat4 view;\n"
"void main() {\n"
"	gl_Position = projection * view * transform * vec4(aPos, 1.0);\n"
"	texCoords = aTexCoords;\n"
"}\n";

const char* vert_bouncy =
"#version 430 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoords;\n"
"out vec2 texCoords;\n"
"uniform float time;\n"
"uniform mat4 transform;\n"
"uniform mat4 projection;\n"
"uniform mat4 view;\n"
"void main() {\n"
"	gl_Position = projection * view * transform * vec4(aPos.x+cos(time*2)/2, aPos.y+sin(time*2)/2, aPos.z, 1);\n"
"	texCoords = aTexCoords;\n"
"}\n";

const char* frag_unlit =
"#version 430 core\n"
"out vec4 fragColor;\n"
"in vec2 texCoords;\n"
"uniform sampler2D tex;\n"
"void main() {\n"
"	fragColor = texture(tex, texCoords);\n"
"}\n";
