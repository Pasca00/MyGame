#pragma once

#include "Texture.h"
#include "Shader.h"

class FrameBuffer {
	private:
		GLuint fbo;
		GLuint textureBuffer;

	public:
		FrameBuffer(Shader* shader);

		void bind();
		void unbind();

		void draw();

		GLuint getTextureID();

		Shader* shader;
};