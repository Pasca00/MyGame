#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine(int g, int maxFallSpeed, int friction) {
	this->g = g;
	this->maxFallSpeed = maxFallSpeed;
	this->friction = friction;
}

void PhysicsEngine::applyGravity(Player* player) {
	
}

void PhysicsEngine::applyFriction(Player* player) {
	if (player->getVelocity() - friction < 0) {
		player->setVelocity(0);
	} else {
		player->setVelocity(player->getVelocity() - friction);
	}
}
