#include <algorithm>

#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine(int g, int maxFallSpeed, int friction, int airFriction, int* timeMultiplier) {
	this->g = g;
	this->maxFallSpeed = maxFallSpeed;
	this->friction = friction;
	this->airFriction = airFriction;

	this->timeMultiplier = timeMultiplier;

	this->updateTime = BASE_PHYSICS_UPDATE_TIME;
	this->lastUpdate = 0;
}

void PhysicsEngine::attach(Movable* o) {
	objects.push_back(o);
}

void PhysicsEngine::detatch(Movable* o) {
	objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
}

void PhysicsEngine::applyGravity(Movable* o) {
	if (o->getYVelocity() + g < maxFallSpeed) {
		o->setYVelocity(o->getYVelocity() + g);
	} else {
		o->setYVelocity(maxFallSpeed);
	}
}

void PhysicsEngine::applyFriction(Movable* o) {
	if (o->collidesDown()) {
		if (o->getXVelocity() - friction < 0) {
			o->setXVelocity(0);
		}
		else {
			o->setXVelocity(o->getXVelocity() - friction);
		}
	}
}

void PhysicsEngine::moveObject(Movable* o) {
	SDL_Rect* rect = o->getRectAddress();

	if (!o->collidesLeft() && !o->collidesRight()) {
		rect->x += o->getXVelocity() * o->getXDirection();
	}

	if (!o->collidesDown() && !o->collidesUp()) {
		rect->y += o->getYVelocity() * o->getYDirection();
	}
}

void PhysicsEngine::accelerate(Movable* o) {
	if (o->isAccelerating()) {
		if (o->getXVelocity() + o->getAcceleration() >= o->getXVelocityCap()) {
			o->setXVelocity(o->getXVelocityCap());
		}
		else {
			o->setXVelocity(o->getXVelocity() + o->getAcceleration());
		}
	}
}

void PhysicsEngine::update() {
	if (Game::getInstance()->getCurrentTime() - lastUpdate >= updateTime * (*timeMultiplier)) {
		for (int i = 0; i < objects.size(); i++) {
			accelerate(objects[i]);
			applyFriction(objects[i]);
			applyGravity(objects[i]);
			moveObject(objects[i]);
		}

		lastUpdate = Game::getInstance()->getCurrentTime();
	}
}

void PhysicsEngine::setUpdateTime(Uint32 updateTime) {
	this->updateTime = updateTime;
}

Uint32 PhysicsEngine::getUpdateTime() {
	return updateTime;
}

