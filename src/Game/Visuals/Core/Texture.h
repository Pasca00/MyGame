#pragma once

#define GLEW_STATIC
#include <gl/glew.h>

class Texture {
	private:
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

		int getWidth();
		int getHeight();
		int getChannels();

		GLuint getTextureID();

		int width;
		int height;
};