#include <algorithm>

#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine(int g, int maxFallSpeed, int friction) {
	this->g = g;
	this->maxFallSpeed = maxFallSpeed;
	this->friction = friction;

	this->updateTime = BASE_PHYSICS_UPDATE_TIME;
	this->lastUpdate = 0;
}

void PhysicsEngine::attach(Movable* o) {
	objects.push_back(o);
}

void PhysicsEngine::detatch(Movable* o) {
	objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
}

void PhysicsEngine::applyGravity() {
	
}

void PhysicsEngine::applyFriction() {
	/*
	if (player->getVelocity() - friction < 0) {
		player->setVelocity(0);
	} else {
		player->setVelocity(player->getVelocity() - friction);
	}
	*/

	if (Game::getInstance()->getCurrentTime() - lastUpdate >= updateTime) {
		for (int i = 0; i < objects.size(); i++) {
			if (objects[i]->getVelocity() - friction < 0) {
				objects[i]->setVelocity(0);
			}
			else {
				objects[i]->setVelocity(objects[i]->getVelocity() - friction);
			}
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

