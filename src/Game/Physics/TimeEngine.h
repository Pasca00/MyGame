#pragma once

#include "../Game.h"

class TimeEngine {
	private:
		static TimeEngine* instance;

		bool timeSlowed;

		int physicsTimeMultiplier;
		int animationTimeMultiplier;

		int currentPhysicsMultiplier;
		int currentAnimationMultiplier;

		TimeEngine(int physicsTimeMultiplier, int animationTimeMultiplier);
		TimeEngine();

		Uint32 stopTime;

	public:
		static TimeEngine* getInstance();

		int getPhysicsMultilpier();
		int getAnimationMultiplier();
		
		int* getPhysicsMultilpierAddress();
		int* getAnimationMultiplierAddress();

		void slowDown();
		void returnToNormal();

		bool isSlowed();

		Uint32 getStopTime();
};

