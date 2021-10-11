#pragma once

#include <vector>

#include "Movable.h"
#include "../Visuals/TileView.h"

class CollisionEngine {
	private:
		int leftBound;
		int rightBound;

	public:
		CollisionEngine(int leftBound, int rightBound);

		void checkBoundsCollision(Movable* o);
		void checkCollision(Movable* p, View* v);
		void applyPlayerCollisionsOnTiles(Movable* p, std::vector< std::vector<TileView*> >& tiles);
};

