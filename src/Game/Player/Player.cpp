#include "Player.h"
#include "../Game.h"

Player::Player(int health, SDL_Rect posRect, int8_t direction) : Movable(0, 0, 3, 6, DIRECTION_RIGHT) {
	this->health = 100;
	this->posRect = posRect;

	this->idleState = new IdlePlayerState();
	this->walkingState = new WalkingPlayerState(this);
	this->currentState_ = idleState;
}

void Player::handleInput(Input* input) {
	currentState_->handleInput(this, input);
}

void Player::update() {
	posRect.x += velocity * direction;

	renderRect = buildRenderRect();
	currentState_->update();
}

SDL_Rect Player::buildRenderRect() {
	SDL_Rect rect;
	rect.x = this->posRect.x;
	rect.y = this->posRect.y;
	rect.w = currentState_->getCurrentFrame()->dstrect.w;
	rect.h = currentState_->getCurrentFrame()->dstrect.h;

	return rect;
}

void Player::setRect(SDL_Rect posRect) {
	this->posRect = posRect;
}

void Player::draw() {
	SDL_Rect renderRect = buildRenderRect();

	if (direction == DIRECTION_RIGHT) {
		Game::getInstance()->getRenderer()->addToQueue(renderRect, currentState_->getCurrentTexture());
	} else {
		Game::getInstance()->getRenderer()->addToQueueFlipped(renderRect, currentState_->getCurrentTexture(), SDL_FLIP_HORIZONTAL);
	}
}

SDL_Texture* Player::getCurrentTexture() {
	return currentState_->getCurrentTexture();
}

SDL_Rect Player::getRect() {
	return posRect;
}

void Player::setState(PlayerState* state) {
	this->currentState_ = state;
}