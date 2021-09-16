#include "Movable.h"

Movable::Movable(int velocity, int fallSpeed, int acceleration, int velocityCap, signed char direction) {
	this->velocity = velocity;
	this->fallSpeed = fallSpeed;
	this->acceleration = acceleration;
	this->velocityCap = velocityCap;

	this->direction = direction;
}

void Movable::setAcceleration(int acceleration) {
	this->acceleration = acceleration;
}

int Movable::getAcceleration() {
	return acceleration;
}

void Movable::setDirection(signed char direction) {
	this->direction = direction;
}

signed char Movable::getDirection() {
	return direction;
}

void Movable::setVelocity(int velocity) {
	this->velocity = velocity;
}

int Movable::getVelocity() {
	return velocity;
}

void Movable::accelerate() {
	if (velocity + acceleration >= velocityCap) {
		velocity = velocityCap;
	}
	else {
		velocity += acceleration;
	}
}