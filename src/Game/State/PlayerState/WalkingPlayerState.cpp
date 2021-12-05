#include "WalkingPlayerState.h"
#include "../../Game.h"
#include "../../Physics/TimeEngine.h"
#include "../../Visuals/TextureBag/TextureBag.h"

WalkingPlayerState::WalkingPlayerState(Player* player) : PlayerState() {
	this->player = player;

	std::vector<Texture*>& textures = TextureBag::getInstance()->getInstance()->playerTextures["walking"];
	SDL_Rect dimensions;

	//SDL_QueryTexture(textures[0], NULL, NULL, &(dimensions.w), &(dimensions.h));
	dimensions.w *= 3;
	dimensions.h *= 3;

	animation = new Animation(textures, 150, 0, 0, 3);
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