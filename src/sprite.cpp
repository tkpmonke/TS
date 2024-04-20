#include "../include/sprite.h"
#include "../libs/include/stb_image.h"
#include "../include/meshes.h"


Texture::Texture(char* location)
{
	this->location = location;
	stbi_set_flip_vertically_on_load(true);
	this->data = stbi_load(location, &width, &height, &channels, 0);
}


void Sprite::Begin(TS* t)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex->glLocation);
	glUseProgram(shader->program);

	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, glm::vec3(x, y, z));
	trans = glm::scale(trans, glm::vec3(scale_x, scale_y, scale_z));

	glm::mat4 proj = glm::mat4(1.0f);
	float aspect = (float)t->width / t->height;
	proj = glm::ortho(-aspect, aspect, -1.0f, +1.0f, 0.1f, 100.0f);

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(t->x, t->y, -10));
	view = glm::scale(view, glm::vec3(t->size, t->size, t->size));

	shader->SetValue(trans, "transform");
	shader->SetValue(proj, "projection");
	shader->SetValue(view, "view");
}

void Sprite::Render(TS* t)
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Sprite::CreateVertexBuffer()
{
    unsigned int vbo, ebo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square_vertices), square_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(square_faces), square_faces, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
	
}

void Sprite::CreateTexture(Texture* t)
{
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, t->texMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, t->texMode);
	if (t->data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, t->width, t->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, t->data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		TS_ERROR("Failed to load texture");
	}
	t->glLocation = texture;
	//stbi_image_free(t);

}