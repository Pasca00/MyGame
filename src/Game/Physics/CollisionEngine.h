#pragma once

#include <vector>

#include "Movable.h"
#include "../Visuals/TileView.h"

class CollisionEngine {
	private:

	public:
		CollisionEngine();

		void checkCollision(Movable* p, View* v);
		void applyPlayerCollisionsOnTiles(Movable* p, std::vector< std::vector<TileView*> > tiles);
};

