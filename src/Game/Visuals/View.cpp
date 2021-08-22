#include "View.h"

View::View(SDL_Renderer* renderer, const char* path) {
	texture = IMG_LoadTexture(renderer, path);
}

View::~View() {
	SDL_DestroyTexture(texture);
}