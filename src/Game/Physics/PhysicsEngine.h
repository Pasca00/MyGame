#pragma once

#include "../Game.h"
#include "Movable.h"

#define BASE_PHYSICS_UPDATE_TIME 25

class PhysicsEngine {
	private:
		std::vector<Movable*> objects;

		int g;
		int maxFallSpeed;
		int friction;
		int airFriction;

		Uint32 updateTime;
		Uint32 lastUpdate;

	public:
		PhysicsEngine(int g, int maxFallSpeed, int friction, int airFriction);

		void attach(Movable* o);
		void detatch(Movable* o);

		void applyGravity(Movable* o);
		void applyFriction(Movable* o);
		void accelerate(Movable* o);

		void update();

		void setUpdateTime(Uint32 updateTime);
		Uint32 getUpdateTime();
};

