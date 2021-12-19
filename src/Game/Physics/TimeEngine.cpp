#include "TimeEngine.h"

TimeEngine* TimeEngine::instance = NULL;

TimeEngine::TimeEngine(int physicsTimeMultiplier, int animationTimeMultiplier) {
	this->physicsTimeMultiplier = physicsTimeMultiplier;
	this->animationTimeMultiplier = animationTimeMultiplier;

	this->timeSlowed = false;
	this->stopTime = 0;

	this->currentAnimationMultiplier = this->currentPhysicsMultiplier = 1;
}

TimeEngine::TimeEngine() {
	physicsTimeMultiplier = 5;
	animationTimeMultiplier = 2;

	timeSlowed = false;
	stopTime = 0;

	currentAnimationMultiplier = currentPhysicsMultiplier = 1;
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
	timeSlowed = true;
	if (stopTime == 0) {
		stopTime = Game::getInstance()->getCurrentTime();
	}


	currentAnimationMultiplier = animationTimeMultiplier;
	currentPhysicsMultiplier = physicsTimeMultiplier;
}

void TimeEngine::returnToNormal() {
	timeSlowed = false;

	stopTime = 0;

	currentAnimationMultiplier = 1;
	currentPhysicsMultiplier = 1;
}

bool TimeEngine::isSlowed() {
	return timeSlowed;
}

Uint32 TimeEngine::getStopTime() {
	return stopTime;
}
