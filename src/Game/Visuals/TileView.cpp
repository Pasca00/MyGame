#include "TileView.h"

TileView::TileView(Texture* texture, Hitbox* hitbox, bool passable) : View(texture, hitbox) {
	this->passable = passable;
}

TileView::TileView(Texture* texture, bool passable, int x, int y, int sizeMultiplier)
	: View(texture, x, y, sizeMultiplier){
	this->passable = passable;
}

bool TileView::isPassable() {
	return passable;
}