#include "IdlePlayerState.h"
#include "../../Game.h"
#include "../../Physics/TimeEngine.h"
#include "../../Visuals/TextureBag/TextureBag.h"

IdlePlayerState::IdlePlayerState() {
	numberOfFrames = 6;

	std::vector<Texture*>& textures = TextureBag::getInstance()->playerTextures["idle"];
	SDL_Rect dimensions;

	//SDL_QueryTexture(textures[0], NULL, NULL, &(dimensions.w), &(dimensions.h));
	dimensions.w *= 3;
	dimensions.h *= 3;
	
	animation = new Animation(textures, 250, 0, 0, 3);
	animation->setTimeMultiplier(TimeEngine::getInstance()->getAnimationMultiplierAddress());
}

void IdlePlayerState::handleInput(Player* player, Input* input) {
	player->stopAccelerating();

	if (input->KEY_D) {
		if (player->getXDirection() == DIRECTION_RIGHT) {
			if (!player->collidesRight()) {
				player->setState(player->walkingState);
			}
		} else {
			player->setXDirection(DIRECTION_RIGHT);
		}

		return;
	}

	if (input->KEY_A) {
		if (player->getXDirection() == DIRECTION_LEFT) {
			if (!player->collidesRight()) {
				player->setState(player->walkingState);
			}
		} else {
			player->setXDirection(DIRECTION_LEFT);
		}
		
		return;
	}

	if (input->LEFT_MOUSE_CLICK) {
		player->setState(player->attackState);
	}

	if (!player->collidesDown()) {
		player->setState(player->fallingState);
		return;
	}

	if (input->KEY_SPACE) {
		player->jump();
		return;
	}
}

void IdlePlayerState::update() {
	animation->update();
}

void IdlePlayerState::draw() { }
