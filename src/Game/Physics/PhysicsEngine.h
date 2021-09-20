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

		Uint32 updateTime;
		Uint32 lastUpdate;

	public:
		PhysicsEngine(int g, int maxFallSpeed, int friction);

		void attach(Movable* o);
		void detatch(Movable* o);

		void applyGravity();
		void applyFriction();

		void update();

		void setUpdateTime(Uint32 updateTime);
		Uint32 getUpdateTime();
};

