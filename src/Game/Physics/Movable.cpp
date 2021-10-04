#include "Movable.h"
#include "../Game.h"

Movable::Movable(int velocity, int fallSpeed, int acceleration, int velocityCap, signed char xDirection, signed char yDirection) {
	this->xVelocity = velocity;
	this->yVelocity = fallSpeed;
	this->acceleration = acceleration;
	this->velocityCap = velocityCap;

	this->xDirection = xDirection;
	this->yDirection = yDirection;

	this->collisionDown = false;
	this->collisionUp = false;
	this->collisionLeft = false;
	this->collisionRight = false;
}

void Movable::setAcceleration(int acceleration) {
	this->acceleration = acceleration;
}

int Movable::getAcceleration() {
	return acceleration;
}

void Movable::setLeftCollision(bool v) {
	this->collisionLeft = v;
}

void Movable::setRightCollision(bool v) {
	this->collisionRight = v;
}

void Movable::setDownCollision(bool v) {
	this->collisionDown = v;
}

void Movable::setUpCollision(bool v) {
	this->collisionUp = v;
}

bool Movable::collidesDown() {
	return collisionDown;
}

bool Movable::collidesUp() {
	return collisionUp;
}

bool Movable::collidesLeft() {
	return collisionLeft;
}

bool Movable::collidesRight() {
	return collisionRight;
}

void Movable::setXDirection(signed char direction) {
	this->xDirection = direction;
}

signed char Movable::getXDirection() {
	return xDirection;
}

void Movable::setXVelocity(int xVelocity) {
	this->xVelocity = xVelocity;
}

int Movable::getXVelocity() {
	return xVelocity;
}

void Movable::setYDirection(signed char yDirection) {
	this->yDirection = yDirection;
}

signed char Movable::getYDirection() {
	return yDirection;
}

void Movable::setYVelocity(int yVelocity) {
	this->yVelocity = yVelocity;
}

int Movable::getYVelocity() {
	return yVelocity;
}

void Movable::setRect(SDL_Rect dstrect) {
	this->dstrect = dstrect;
}

SDL_Rect Movable::getRect() {
	return dstrect;
}

SDL_Rect* Movable::getRectAddress() {
	return &dstrect;
}

void Movable::accelerate() {
	if (xVelocity + acceleration >= velocityCap) {
		xVelocity = velocityCap;
	}
	else {
		xVelocity += acceleration;
	}
}