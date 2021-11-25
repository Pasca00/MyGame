#include "AttackPlayerState.h"
#include "../../Game.h"
#include "../../Physics/TimeEngine.h"
#include "../../Player/Player.h"
#include "../../Visuals/TextureBag/TextureBag.h"

AttackPlayerState::AttackPlayerState(Player* player) {
	this->player = player;
	secondAttackRequested = false;

	std::vector<SDL_Texture*>& textures = TextureBag::getInstance()->playerTextures["firstAttack"];
	SDL_Rect dimensions;
	SDL_QueryTexture(textures[0], NULL, NULL, &dimensions.w, &dimensions.h);
	dimensions.w *= 3;
	dimensions.h *= 3;

	firstAttackAnimation = new Animation(textures, dimensions, 90);
	firstAttackAnimation->setTimeMultiplier(TimeEngine::getInstance()->getAnimationMultiplierAddress());

	std::vector<SDL_Texture*>& secondAttackTextures = TextureBag::getInstance()->playerTextures["secondAttack"];
	secondAttackAnimation = new Animation(secondAttackTextures, dimensions, 90);
	secondAttackAnimation->setTimeMultiplier(TimeEngine::getInstance()->getAnimationMultiplierAddress());

	animation = firstAttackAnimation;
}

void AttackPlayerState::handleInput(Player* player, Input* input) {
	player->stopAccelerating();

	if (input->KEY_A) {
		player->startAccelerating();
	} else if (input->KEY_D) {
		player->startAccelerating();
	}

	if (input->LEFT_MOUSE_CLICK) {
		secondAttackRequested = true;
	}
}

void AttackPlayerState::update() {
	animation->update();
	
	if (animation->isDone()) {
		if (animation == firstAttackAnimation) {
			if (secondAttackRequested) {
				animation = secondAttackAnimation;
			} else {
				player->setState(player->idleState);
			}
		} else {
			player->setState(player->idleState);
		}
	}
}

void AttackPlayerState::draw() { }

void AttackPlayerState::resetAnimation() {
	secondAttackRequested = false;
	animation = firstAttackAnimation;
	firstAttackAnimation->reset();
	secondAttackAnimation->reset();
}