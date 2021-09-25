#include "Movable.h"

Movable::Movable(int velocity, int fallSpeed, int acceleration, int velocityCap, signed char direction) {
	this->xVelocity = velocity;
	this->yVelocity = fallSpeed;
	this->acceleration = acceleration;
	this->velocityCap = velocityCap;

	this->xDirection = direction;

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

void Movable::setDirection(signed char direction) {
	this->xDirection = direction;
}

signed char Movable::getDirection() {
	return xDirection;
}

void Movable::setVelocity(int velocity) {
	this->xVelocity = velocity;
}

int Movable::getVelocity() {
	return xVelocity;
}

void Movable::accelerate() {
	if (xVelocity + acceleration >= velocityCap) {
		xVelocity = velocityCap;
	}
	else {
		xVelocity += acceleration;
	}
}