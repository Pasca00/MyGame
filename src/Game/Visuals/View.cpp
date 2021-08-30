#include "View.h"

View::View(SDL_Texture* texture, SDL_Rect dstrect) {
	this->texture = texture;
	this->dstrect = dstrect;
}

View::~View() {
	//SDL_DestroyTexture(texture);
}