#include "Renderer.h"

Renderer::Renderer(Window* window) {
	drawR = 0;
	drawG = 0;
	drawB = 0;

	renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, drawR, drawG, drawB, SDL_ALPHA_OPAQUE);
}

void Renderer::addToQueue(View* view) {
	SDL_RenderCopy(renderer, view->texture, NULL, &(view->dstrect));
}

void Renderer::clearScreen() {
	SDL_RenderClear(renderer);
}

void Renderer::renderQueue() {
	SDL_RenderPresent(renderer);
}

void Renderer::updateColors() {
	drawR += 1;
	drawG += 2;
	drawB -= 1;
	
	SDL_SetRenderDrawColor(renderer, drawR, drawG, drawB, SDL_ALPHA_OPAQUE);
}

SDL_Renderer* Renderer::getSDLRenderer() {
	return renderer;
}