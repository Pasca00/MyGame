#include "Movable.h"
#include "../Game.h"

Movable::Movable(float velocity, float jumpSpeed, float fallSpeed, float acceleration, float velocityCap, signed char xDirection, signed char yDirection) {
	this->xVelocity = velocity;
	this->yVelocity = fallSpeed;
	this->jumpSpeed = jumpSpeed;
	this->acceleration = acceleration;
	this->velocityCap = velocityCap;

	this->hitbox = NULL;

	this->xDirection = xDirection;
	this->yDirection = yDirection;

	this->accelerating = false;

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

void Movable::startAccelerating() {
	accelerating = true;
}

void Movable::stopAccelerating() {
	accelerating = false;
}

bool Movable::isAccelerating() {
	return accelerating;
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

void Movable::setXVelocityCap(int xVelocityCap) {
	this->velocityCap = xVelocityCap;
}

int Movable::getXVelocityCap() {
	return velocityCap;
}

void Movable::setHitbox(Hitbox* hitbox) {
	this->hitbox = hitbox;
}

Hitbox* Movable::getHitbox() {
	return hitbox;
}

void Movable::accelerate() {
	if (xVelocity + acceleration >= velocityCap) {
		xVelocity = velocityCap;
	}
	else {
		xVelocity += acceleration;
	}
}

void Movable::jump() {
	yVelocity = -jumpSpeed;
	//xVelocity += 7;
}