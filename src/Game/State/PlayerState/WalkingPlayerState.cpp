#include "WalkingPlayerState.h"
#include "../../Game.h"
#include "../../Physics/TimeEngine.h"

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
	animation->setTimeMultiplier(TimeEngine::getInstance()->getAnimationMultiplierAddress());
}

void WalkingPlayerState::handleInput(Player* player, Input* input) {
	if ((player->getXDirection() == DIRECTION_RIGHT && input->KEY_D == 0) 
		|| player->getXDirection() == DIRECTION_RIGHT && player->collidesRight()) {
		player->setState(player->idleState);
		return;
	}

	if ((player->getXDirection() == DIRECTION_LEFT && input->KEY_A == 0) 
		|| player->getXDirection() == DIRECTION_RIGHT && player->collidesLeft()) {
		player->setState(player->idleState);
		return;
	}

	if (!player->collidesDown()) {
		player->setState(player->fallingState);
		return;
	}

	if (input->KEY_SPACE) {
		player->jump();
		player->setXVelocity(7);
		player->stopAccelerating();
		return;
	}

	if (input->LEFT_MOUSE_CLICK) {
		player->setState(player->attackState);
	}

	player->startAccelerating();
}

void WalkingPlayerState::update() {
	animation->update();
}

void WalkingPlayerState::draw() { }