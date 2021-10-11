#include "TimeEngine.h"

TimeEngine* TimeEngine::instance = NULL;

TimeEngine::TimeEngine(int physicsTimeMultiplier, int animationTimeMultiplier) {
	this->physicsTimeMultiplier = physicsTimeMultiplier;
	this->animationTimeMultiplier = animationTimeMultiplier;

	this->currentAnimationMultiplier = this->currentPhysicsMultiplier = 1;
}

TimeEngine::TimeEngine() {
	physicsTimeMultiplier = 5;
	animationTimeMultiplier = 2;

	this->currentAnimationMultiplier = this->currentPhysicsMultiplier = 1;
}

TimeEngine* TimeEngine::getInstance() {
	if (instance == NULL) {
		instance = new TimeEngine();
	}

	return instance;
}

int* TimeEngine::getPhysicsMultilpierAddress() {
	return &currentPhysicsMultiplier;
}

int* TimeEngine::getAnimationMultiplierAddress() {
	return &currentAnimationMultiplier;
}

int TimeEngine::getPhysicsMultilpier() {
	return currentPhysicsMultiplier;
}

int TimeEngine::getAnimationMultiplier() {
	return currentAnimationMultiplier;
}

void TimeEngine::slowDown() {
	this->currentAnimationMultiplier = animationTimeMultiplier;
	this->currentPhysicsMultiplier = physicsTimeMultiplier;
}

void TimeEngine::returnToNormal() {
	this->currentAnimationMultiplier = 1;
	this->currentPhysicsMultiplier = 1;
}
