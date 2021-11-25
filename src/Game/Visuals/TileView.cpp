#include "TileView.h"

TileView::TileView(SDL_Texture* texture, SDL_Rect dstrect, bool passable) : View(texture, dstrect) {
	this->passable = passable;
}

TileView::TileView(SDL_Texture* texture, bool passable, int x, int y, int sizeMultiplier)
	: View(texture, x, y, sizeMultiplier){
	this->passable = passable;
}

bool TileView::isPassable() {
	return passable;
}