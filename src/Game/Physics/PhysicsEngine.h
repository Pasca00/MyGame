#pragma once

#include "../Game.h"
#include "Movable.h"

#define BASE_PHYSICS_UPDATE_TIME 10

class PhysicsEngine {
	private:
		std::vector<Movable*> objects;

		int g;
		int maxFallSpeed;
		int friction;
		int airFriction;

		int* timeMultiplier;

		Uint32 updateTime;
		Uint32 lastUpdate;

	public:
		PhysicsEngine(int g, int maxFallSpeed, int friction, int airFriction, int* timeMultiplier);

		void attach(Movable* o);
		void detatch(Movable* o);

		void applyGravity(Movable* o);
		void applyFriction(Movable* o);
		void accelerate(Movable* o);
		void moveObject(Movable* o);

		void update();

		void setUpdateTime(Uint32 updateTime);
		Uint32 getUpdateTime();
};

