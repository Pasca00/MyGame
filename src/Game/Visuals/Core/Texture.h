#pragma once

#define GLEW_STATIC
#include <gl/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../../stb_image.h"

class Texture {
	private:
		int width;
		int height;
		int channels;

		GLuint targetType;
		GLuint textureID;
		
		GLenum wrappingMode;

		GLenum textureMinFilter;
		GLenum textureMagFilter;

		unsigned char* imageData;

	public:
		Texture();
		Texture(const char* filepath);

		void loadImage(const char* filepath);
};