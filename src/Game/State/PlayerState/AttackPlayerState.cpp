#include "AttackPlayerState.h"
#include "../../Game.h"
#include "../../Physics/TimeEngine.h"
#include "../../Player/Player.h"

AttackPlayerState::AttackPlayerState(Player* player) {
	this->player = player;
	secondAttackRequested = false;

	numberOfFrames = 5;
	numberOfFramesSecondAttack = 3;

	std::vector<SDL_Texture*> textures(numberOfFrames, NULL);
	SDL_Rect dimensions;
	for (int i = 0; i < numberOfFrames; i++) {
		char filePath[100];
		sprintf(filePath, "C:/Users/alexp/Desktop/Game/resources/Player/player_attack%d.png", i + 1);
		textures[i] = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(), filePath);
	}

	SDL_QueryTexture(textures[0], NULL, NULL, &dimensions.w, &dimensions.h);
	dimensions.w *= 3;
	dimensions.h *= 3;

	firstAttackAnimation = new Animation(textures, dimensions, 90);
	firstAttackAnimation->setTimeMultiplier(TimeEngine::getInstance()->getAnimationMultiplierAddress());

	std::vector<SDL_Texture*> secondAttackTextures(numberOfFramesSecondAttack, NULL);
	for (int i = 0; i < numberOfFramesSecondAttack; i++) {
		char filePath[100];
		sprintf(filePath, "C:/Users/alexp/Desktop/Game/resources/Player/player_attack%d.png", numberOfFrames + i + 1);
		secondAttackTextures[i] = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(), filePath);
	}

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