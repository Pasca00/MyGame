#include "FallingPlayerState.h"
#include "../../Game.h"
#include "../../Physics/TimeEngine.h"
#include "../../Visuals/TextureBag/TextureBag.h"

FallingPlayerState::FallingPlayerState() {
	std::vector<SDL_Texture*>& textures = TextureBag::getInstance()->playerTextures["idle"];
	SDL_Rect dimensions;

	SDL_QueryTexture(textures[0], NULL, NULL, &(dimensions.w), &(dimensions.h));
	dimensions.w *= 3;
	dimensions.h *= 3;

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