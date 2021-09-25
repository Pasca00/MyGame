#pragma once

#include "../Player/Player.h"
#include "../Visuals/View.h"

class CollisionEngine {
	private:

	public:
		CollisionEngine();

		void checkCollision(Player* p, View* v);
};

