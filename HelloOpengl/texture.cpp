#include "texture.h"
#include <glad/glad.h>
#include "stb_image.h"
void texture::generateTexture(std::string file, unsigned format) {
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void texture::activeTexture(unsigned int texID) {
	glActiveTexture(texID);
}

void texture::bindTexture() {
	glBindTexture(GL_TEXTURE_2D, textureID);
}