#include "CollisionEngine.h"

CollisionEngine::CollisionEngine() { }

void CollisionEngine::checkCollision(Movable* p, View* v) {
	SDL_Rect* rect = p->getRectAddress();

	if ((rect->y + rect->h >= v->dstrect.y && rect->y + rect->h < v->dstrect.y + v->dstrect.h)
		|| (rect->y < v->dstrect.y + v->dstrect.h && rect->y >= v->dstrect.y)) {
		if (p->getXDirection() == DIRECTION_LEFT) {
			if (rect->x + p->getXDirection() * p->getXVelocity() < v->dstrect.x + v->dstrect.w
				&& rect->x + p->getXDirection() * p->getXVelocity() >= v->dstrect.x) {
				p->setLeftCollision(true);
				rect->x = v->dstrect.x + v->dstrect.w + 1;
			}
		} else if (p->getXDirection() == DIRECTION_RIGHT) {
			if (rect->x + rect->w + p->getXVelocity() >= v->dstrect.x
				&& rect->x + rect->w + p->getXVelocity() < v->dstrect.x + v->dstrect.w) {
				p->setRightCollision(true);
				rect->x = v->dstrect.x - rect->w;
			}
		}
	}

	if ((rect->x + rect->w >= v->dstrect.x && rect->x + rect->w < v->dstrect.x + v->dstrect.w)
		|| (rect->x < v->dstrect.x + v->dstrect.w && rect->x >= v->dstrect.x)) {
		if (p->getYDirection() == DIRECTION_DOWN && !p->collidesDown()) {
			if (rect->y + rect->h + p->getYVelocity() >= v->dstrect.y
				&& rect->y + rect->h + p->getYVelocity() < v->dstrect.y + v->dstrect.h) {
				p->setDownCollision(true);
				rect->y = v->dstrect.y - rect->h - 1;
			}
		}
		else if (p->getYDirection() == DIRECTION_UP && !p->collidesUp()) {
			if (rect->y - p->getYDirection() < v->dstrect.y + v->dstrect.h
				&& rect->y - p->getYDirection() >= v->dstrect.y) {
				p->setUpCollision(true);
				rect->y = v->dstrect.w + v->dstrect.h;
			}
		}
	}
}

void CollisionEngine::applyPlayerCollisionsOnTiles(Movable* p, std::vector< std::vector<TileView*> > tiles) {
	p->setLeftCollision(false);
	p->setRightCollision(false);
	p->setUpCollision(false);
	p->setDownCollision(false);

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