#include "Player.h"
#include "../Game.h"
#include "../Physics/TimeEngine.h"

Player::Player(int health, SDL_Rect dstrect, int8_t direction) 
	: Movable(0, 0, 3, 6, DIRECTION_RIGHT, DIRECTION_DOWN) {
	this->health = health;

	this->textureW = 45;
	this->textureH = 71;

	this->dstrect = dstrect;

	this->dstrect.w = textureW * 3;
	this->dstrect.h = textureH * 3;

	this->sizeMultiplier = 1;

	this->idleState = new IdlePlayerState();
	this->walkingState = new WalkingPlayerState(this);
	this->fallingState = new FallingPlayerState();
	this->currentState_ = idleState;
}

void Player::handleInput(Input* input) {
	if (input->KEY_SHIFT) {
		TimeEngine::getInstance()->slowDown();
	} else {
		TimeEngine::getInstance()->returnToNormal();
	}

	currentState_->handleInput(this, input);
}

void Player::update() {
	currentState_->update();
}

void Player::draw() {
	if (xDirection == DIRECTION_RIGHT) {
		Game::getInstance()->getRenderer()->addToQueue(dstrect, currentState_->getCurrentTexture());
	} else {
		Game::getInstance()->getRenderer()->addToQueueFlipped(dstrect, currentState_->getCurrentTexture(), SDL_FLIP_HORIZONTAL);
	}
}

void Player::drawToRelativePosition(SDL_Rect cameraPos) {
	SDL_Rect renderRect = dstrect;
	renderRect.x -= cameraPos.x;

	if (xDirection == DIRECTION_RIGHT) {
		Game::getInstance()->getRenderer()->addToQueue(renderRect, currentState_->getCurrentTexture());
	}
	else {
		Game::getInstance()->getRenderer()->addToQueueFlipped(renderRect, currentState_->getCurrentTexture(), SDL_FLIP_HORIZONTAL);
	}
}

SDL_Texture* Player::getCurrentTexture() {
	return currentState_->getCurrentTexture();
}

void Player::setState(PlayerState* state) {
	this->currentState_ = state;
}