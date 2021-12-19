#include "FallingPlayerState.h"
#include "../../Game.h"
#include "../../Physics/TimeEngine.h"
#include "../../Visuals/TextureBag/TextureBag.h"

FallingPlayerState::FallingPlayerState() {
	std::vector<Texture*>& textures = TextureBag::getInstance()->playerTextures["idle"];

	animation = new Animation(textures, 250, 0, 0, 3);
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