#pragma once

#include "../Game.h"

class TimeEngine {
	private:
		static TimeEngine* instance;

		int physicsTimeMultiplier;
		int animationTimeMultiplier;

		int currentPhysicsMultiplier;
		int currentAnimationMultiplier;

		TimeEngine(int physicsTimeMultiplier, int animationTimeMultiplier);
		TimeEngine();

	public:
		static TimeEngine* getInstance();

		int getPhysicsMultilpier();
		int getAnimationMultiplier();
		
		int* getPhysicsMultilpierAddress();
		int* getAnimationMultiplierAddress();

		void slowDown();
		void returnToNormal();
};

