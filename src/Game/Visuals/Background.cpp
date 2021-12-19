#include "Background.h"
#include "../Window/Window.h"
#include "../Game.h"

Background::Background(const char* backgroundTextureFile, std::vector<const char*> layerTexturesFiles, int numberOfScenes) {
	float x = 0;
	float y = 0;
	float w = (float) Window::BASE_WINDOW_WIDTH;
	float h = (float) Window::BASE_WINDOW_HEIGHT;

	if (backgroundTextureFile == NULL) {
		staticBackground = NULL;
	} else {
		Texture* t_ = new Texture(backgroundTextureFile);
		staticBackground = new View(t_, 0, 0, 3);
	}

	int numberOfLayers = layerTexturesFiles.size();
	parallaxLayers = std::vector<std::vector<View*>>(numberOfLayers);
	for (int i = 0; i < numberOfLayers; i++) {
		parallaxLayers[i] = std::vector<View*>(numberOfScenes * (i + 1), NULL);
		Texture* t_ = new Texture(layerTexturesFiles[i]);
		x = 0;
		for (int j = 0; j < parallaxLayers[i].size(); j++) {
			parallaxLayers[i][j] = new View(t_, x, y, 3);
			x += w;
		}
	}

	baseScrollSpeed = 0;
}

void Background::setBaseScrollSpeed(int baseScrollSpeed) {
	this->baseScrollSpeed = baseScrollSpeed;
}

void Background::scrollLeft() {
	for (int i = 0; i < parallaxLayers.size(); i++) {
		for (int j = 0; j < parallaxLayers[i].size(); j++) {
			parallaxLayers[i][j]->dstrect.x -= baseScrollSpeed + i + 1;
		}
	}
}

void Background::scrollRight() {
	for (int i = 0; i < parallaxLayers.size(); i++) {
		for (int j = 0; j < parallaxLayers[i].size(); j++) {
			parallaxLayers[i][j]->dstrect.x += baseScrollSpeed + i + 1;
		}
	}
}

void Background::draw() {
	if (staticBackground != NULL) {
		Game::getInstance()->getRenderer()->draw(staticBackground, Game::getInstance()->baseTextureShader);
	}

	for (int i = 0; i < parallaxLayers.size(); i++) {
		for (int j = 0; j < parallaxLayers[i].size(); j++) {
			Game::getInstance()->getRenderer()->draw(parallaxLayers[i][j], Game::getInstance()->baseTextureShader);
		}
	}
}

void Background::update(int8_t cameraDirection) {
	if (cameraDirection == 1) {
		scrollLeft();
	} else if (cameraDirection == -1) {
		scrollRight();
	}
}
