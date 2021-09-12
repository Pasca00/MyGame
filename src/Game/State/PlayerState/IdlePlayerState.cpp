#include "IdlePlayerState.h"
#include "../../Game.h"

IdlePlayerState::IdlePlayerState() {
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
}

void IdlePlayerState::handleInput(Player* player, Input* input) {
	if (input->KEY_D) {
		if (player->getDirection() == DIRECTION_RIGHT) {
			player->setState(player->walkingState);
		} else {
			player->setDirection(DIRECTION_RIGHT);
		}

		return;
	}

	if (input->KEY_A) {
		if (player->getDirection() == DIRECTION_LEFT) {
			player->setState(player->walkingState);
		} else {
			player->setDirection(DIRECTION_LEFT);
		}
		
		return;
	}
}

void IdlePlayerState::update() {
	animation->update();
}

void IdlePlayerState::draw() { }