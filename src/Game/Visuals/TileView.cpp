#include "TileView.h"

TileView::TileView(SDL_Texture* texture, SDL_Rect dstrect, bool passable) : View(texture, dstrect) {
	this->passable = passable;
}
