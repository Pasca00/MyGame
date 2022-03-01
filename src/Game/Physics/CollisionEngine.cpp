#include "CollisionEngine.h"

CollisionEngine::CollisionEngine(int leftBound, int rightBound) {
	this->leftBound = leftBound;
	this->rightBound = rightBound;
}

void CollisionEngine::checkCollision(Movable* p, View* v) {
	Hitbox* rect = p->getHitbox();

	if ((rect->y + rect->h >= v->hitbox->y && rect->y + rect->h < v->hitbox->y + v->hitbox->h)
		|| (rect->y < v->hitbox->y + v->hitbox->h && rect->y >= v->hitbox->y)) {
		if (p->getXDirection() == DIRECTION_LEFT) {
			if (rect->x + p->getXDirection() * p->getXVelocity() < v->hitbox->x + v->hitbox->w
				&& rect->x + p->getXDirection() * p->getXVelocity() >= v->hitbox->x) {
				p->setLeftCollision(true);
				rect->x = v->hitbox->x + v->hitbox->w + 1;
			}
		} else if (p->getXDirection() == DIRECTION_RIGHT) {
			if (rect->x + rect->w + p->getXVelocity() >= v->hitbox->x
				&& rect->x + rect->w + p->getXVelocity() < v->hitbox->x + v->hitbox->w) {
				p->setRightCollision(true);
				rect->x = v->hitbox->x - rect->w;
			}
		}
	}

	if ((rect->x + rect->w >= v->hitbox->x && rect->x + rect->w < v->hitbox->x + v->hitbox->w)
		|| (rect->x < v->hitbox->x + v->hitbox->w && rect->x >= v->hitbox->x)) {
		if (p->getYDirection() == DIRECTION_DOWN && !p->collidesDown()) {
			if (rect->y - p->getYVelocity() >= v->hitbox->y
				&& rect->y - p->getYVelocity() < v->hitbox->y + v->hitbox->h) {
				p->setDownCollision(true);
				rect->y = v->hitbox->y + v->hitbox->h + 1;
			}
		} else if (p->getYDirection() == DIRECTION_UP && !p->collidesUp()) {
			if (rect->y + rect->h + p->getYDirection() < v->hitbox->y + v->hitbox->h
				&& rect->y + rect->h + p->getYDirection() >= v->hitbox->y) {
				p->setUpCollision(true);
				rect->y = v->hitbox->y;
			}
		}
	}
}

void CollisionEngine::checkBoundsCollision(Movable* o) {
	Hitbox* rect = o->getHitbox();
	if (rect->x + o->getXVelocity() * o->getXDirection() < leftBound) {
		o->setLeftCollision(true);
		rect->x = leftBound;
	} else if (rect->x + rect->w + o->getXVelocity() * o->getXDirection() >= rightBound) {
		o->setRightCollision(true);
		rect->x = rightBound - rect->w - 1;
	}
}

void CollisionEngine::applyPlayerCollisionsOnTiles(Movable* p, std::vector< std::vector<TileView*> >& tiles) {
	p->setLeftCollision(false);
	p->setRightCollision(false);
	p->setUpCollision(false);
	p->setDownCollision(false);

	checkBoundsCollision(p);

	for (int i = 0; i < tiles.size(); i++) {
		for (int j = 0; j < tiles[i].size(); j++) {
			if (tiles[i][j] != NULL) {
				if (!tiles[i][j]->isPassable()) {
					checkCollision(p, tiles[i][j]);
				}
			}
		}
	}
}