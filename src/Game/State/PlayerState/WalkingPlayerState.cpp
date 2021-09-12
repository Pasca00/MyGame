#include "WalkingPlayerState.h"
#include "../../Game.h"

WalkingPlayerState::WalkingPlayerState(Player* player) : PlayerState() {
	this->player = player;

	numberOfFrames = 7;

	std::vector<SDL_Texture*> textures(numberOfFrames, NULL);
	std::vector<SDL_Rect> dimensions(numberOfFrames);
	for (int i = 0; i < numberOfFrames; i++) {
		char filePath[100];
		sprintf(filePath, "C:/Users/alexp/Desktop/Game/resources/Player/player_walking%d.png", i + 1);
		textures[i] = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(), filePath);

		SDL_QueryTexture(textures[i], NULL, NULL, &(dimensions[i].w), &(dimensions[i].h));
		dimensions[i].w *= 3;
		dimensions[i].h *= 3;
	}

	animation = new Animation(textures, dimensions, 150);
}

void WalkingPlayerState::handleInput(Player* player, Input* input) {
	if (player->getDirection() == DIRECTION_RIGHT && input->KEY_D == 0) {
		player->setState(player->idleState);
		player->setVelocity(0);
	}

	if (player->getDirection() == DIRECTION_LEFT && input->KEY_A == 0) {
		player->setState(player->idleState);
		player->setVelocity(0);
	}
}

void WalkingPlayerState::update() {
	player->accelerate();
	animation->update();
}

void WalkingPlayerState::draw() { }