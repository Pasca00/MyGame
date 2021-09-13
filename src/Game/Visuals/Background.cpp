#include "Background.h"
#include "../Window/Window.h"
#include "../Game.h"

Background::Background(const char* backgroundTextureFile, std::vector<const char*> layerTexturesFiles, int numberOfScenes) {
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = Window::BASE_WINDOW_WIDTH;
	rect.h = Window::BASE_WINDOW_HEIGHT;

	if (backgroundTextureFile == NULL) {
		staticBackground = NULL;
	} else {
		SDL_Texture* t_ = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(), backgroundTextureFile);
		staticBackground = new View(t_, rect);
	}

	int numberOfLayers = layerTexturesFiles.size();
	parallaxLayers = std::vector<std::vector<View*>>(numberOfLayers);
	for (int i = 0; i < numberOfLayers; i++) {
		parallaxLayers[i] = std::vector<View*>(numberOfScenes * (i + 1), NULL);
		SDL_Texture* t_ = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(), layerTexturesFiles[i]);
		rect.x = 0;
		for (int j = 0; j < parallaxLayers[i].size(); j++) {
			parallaxLayers[i][j] = new View(t_, rect);
			rect.x += rect.w;
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
		Game::getInstance()->getRenderer()->addToQueue(staticBackground);
	}

	for (int i = 0; i < parallaxLayers.size(); i++) {
		for (int j = 0; j < parallaxLayers[i].size(); j++) {
			Game::getInstance()->getRenderer()->addToQueue(parallaxLayers[i][j]);
		}
	}
}
