#pragma once


const char* vert_2D =
"#version 430 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main() {\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1);\n"
"}\n";

const char* vert_bouncy =
"#version 430 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform float time;\n"
"void main() {\n"
"	gl_Position = vec4(aPos.x, aPos.y+sin(time*2)/2, aPos.z, 1);\n"
"}\n";

const char* frag_unlit =
"#version 430 core\n"
"out vec4 fragColor;\n"
"void main() {\n"
"	fragColor = vec4(1, 1, 1, 1);\n"
"}\n";
