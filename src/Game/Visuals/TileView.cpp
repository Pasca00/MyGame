#include "TileView.h"

TileView::TileView(Texture* texture, SDL_Rect dstrect, bool passable) : View(texture, dstrect) {
	this->passable = passable;
}

TileView::TileView(Texture* texture, bool passable, int x, int y, int sizeMultiplier)
	: View(texture, x, y, sizeMultiplier){
	this->passable = passable;
}

bool TileView::isPassable() {
	return passable;
}