#include "CollisionEngine.h"

CollisionEngine::CollisionEngine() { }

void CollisionEngine::checkCollision(Player* p, View* v) {
	SDL_Rect* rect = p->getRenderRectAddress();
	if (p->getDirection() == DIRECTION_LEFT) {
		if (rect->x + p->getDirection() * p->getXVelocity() < v->dstrect.x + v->dstrect.w
			&& rect->x + p->getDirection() * p->getXVelocity() >= v->dstrect.x) {
			p->setLeftCollision(true);
			rect->x = v->dstrect.x + v->dstrect.w + 1;
			p->setVelocity(0);
		} else {
			p->setLeftCollision(false);
		}
	} else if (p->getDirection() == DIRECTION_RIGHT) {
		if (rect->x + rect->w + p->getXVelocity() >= v->dstrect.x
			&& rect->x + rect->w + p->getXVelocity() < v->dstrect.x + v->dstrect.w) {
			p->setRightCollision(true);
			rect->x = v->dstrect.x = rect->w;
			p->setVelocity(0);
		} else {
			p->setRightCollision(false);
		}
	}
}