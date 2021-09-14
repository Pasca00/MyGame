#pragma once

#include "../Player/Player.h"

class PhysicsEngine {
	private:
		int g;
		int maxFallSpeed;
		int friction;

	public:
		PhysicsEngine(int g, int maxFallSpeed, int friction);

		void applyGravity(Player* player);
		void applyFriction(Player* player);
};

