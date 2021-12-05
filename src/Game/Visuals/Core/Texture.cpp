#include "Texture.h"

#include "../../stb_image.h"

const GLint pixelFormat[5] = { 0, GL_RED, GL_RG, GL_RGB, GL_RGBA };
const GLint internalFormat[][5] = {
    { 0, GL_R8, GL_RG8, GL_RGB8, GL_RGBA8 },
    { 0, GL_R16, GL_RG16, GL_RGB16, GL_RGBA16 },
    { 0, GL_R16F, GL_RG16F, GL_RGB16F, GL_RGBA16F },
    { 0, GL_R32F, GL_RG32F, GL_RGB32F, GL_RGBA32F }
};

Texture::Texture() {
    width = 0;
    height = 0;
    channels = 0;
    textureID = 0;

    targetType = GL_TEXTURE_2D;
    wrappingMode = GL_REPEAT;

    textureMinFilter = GL_NEAREST;
    textureMagFilter = GL_NEAREST;

    imageData = NULL;
}

Texture::Texture(const char* filepath) : Texture() {
    loadImage(filepath);
}

void Texture::loadImage(const char* filepath) {
    textureMinFilter = GL_NEAREST_MIPMAP_NEAREST;
    textureMagFilter = GL_NEAREST;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureMinFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureMagFilter);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    imageData = stbi_load(filepath, &width, &height, &channels, 0);

    glTexImage2D(targetType, 0, internalFormat[0][channels], width, height, 0, pixelFormat[channels], GL_UNSIGNED_BYTE, imageData);
    glGenerateMipmap(targetType);
    glBindTexture(targetType, 0);

    stbi_image_free(imageData);
}

int Texture::getWidth() {
    return width;
}

int Texture::getHeight() {
    return height;
}

int Texture::getChannels() {
    return channels;
}

GLuint Texture::getTextureID() {
    return textureID;
}