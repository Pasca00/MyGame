#include "FallingPlayerState.h"
#include "../../Game.h"
#include "../../Physics/TimeEngine.h"

FallingPlayerState::FallingPlayerState() {
	numberOfFrames = 6;

	std::vector<SDL_Texture*> textures(numberOfFrames, NULL);
	std::vector<SDL_Rect> dimensions(numberOfFrames);
	for (int i = 0; i < numberOfFrames; i++) {
		char filePath[100];
		sprintf(filePath, "C:/Users/alexp/Desktop/Game/resources/Player/player_idle%d.png", i + 1);
		textures[i] = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(), filePath);

		SDL_QueryTexture(textures[i], NULL, NULL, &(dimensions[i].w), &(dimensions[i].h));
		dimensions[i].w *= 3;
		dimensions[i].h *= 3;
	}

	SDL_Rect rect;
	memset(&rect, 0, sizeof(SDL_Rect));
	animation = new Animation(textures, dimensions, 250);
	animation->setTimeMultiplier(TimeEngine::getInstance()->getAnimationMultiplierAddress());
}

void FallingPlayerState::handleInput(Player* player, Input* input) {
	player->stopAccelerating();

	if (player->collidesDown()) {
		player->setState(player->idleState);
	}

	/*
		Player should be able to attack in this state
	*/
}

void FallingPlayerState::update() {
	animation->update();
}

void FallingPlayerState::draw() { }