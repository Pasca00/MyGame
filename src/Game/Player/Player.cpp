#include "Player.h"
#include "../Game.h"

Player::Player(int health, SDL_Rect posRect, int8_t direction) {
	this->health = 100;
	this->posRect = posRect;
	this->direction = direction;

	this->idleState = new IdlePlayerState();
	this->walkingState = new WalkingPlayerState(this);
	this->currentState_ = idleState;

	this->velocity = 0;
	this->fallSpeed = 0;
	this->acceleration = 3;
	this->accCap = 2;
	this->velocityCap = 6;
}

void Player::handleInput(Input* input) {
	currentState_->handleInput(this, input);
}

void Player::update() {
	posRect.x += velocity * direction;

	renderRect = buildRenderRect();
	currentState_->update();
}

void Player::accelerate() {
	if (velocity + acceleration >= velocityCap) {
		velocity = velocityCap;
	} else {
		velocity += acceleration;
	}
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

void Player::setVelocity(int velocity) {
	this->velocity = velocity;
}

int Player::getVelocity() {
	return velocity;
}

void Player::setAcceleration(int acceleration) {
	this->acceleration = acceleration;
}

int Player::getAcceleration() {
	return acceleration;
}

SDL_Texture* Player::getCurrentTexture() {
	return currentState_->getCurrentTexture();
}

SDL_Rect Player::getRect() {
	return posRect;
}

void Player::setDirection(int8_t direction) {
	this->direction = direction;
}

int8_t Player::getDirection() {
	return direction;
}

void Player::setState(PlayerState* state) {
	this->currentState_ = state;
}