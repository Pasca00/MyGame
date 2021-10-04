#include "Renderer.h"

Renderer::Renderer(Window* window) {
	drawR = 0;
	drawG = 0;
	drawB = 0;

	renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, drawR, drawG, drawB, SDL_ALPHA_OPAQUE);
}

void Renderer::addToQueueFlipped(SDL_Rect dstrect, SDL_Texture* texture, SDL_RendererFlip flipType) {
	SDL_RenderCopyEx(renderer, texture, NULL, &dstrect, 0, NULL, flipType);
}

void Renderer::addToQueue(SDL_Rect dstrect, SDL_Texture* texture) {
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}

void Renderer::addToQueue(View* view) {
	SDL_RenderCopy(renderer, view->texture, NULL, &(view->dstrect));
}

void Renderer::addToQueue(Player* player) {
	SDL_RenderCopy(renderer, player->getCurrentTexture(), NULL, player->getRectAddress());
}

void Renderer::clearScreen() {
	SDL_RenderClear(renderer);
}

void Renderer::renderQueue() {
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::getSDLRenderer() {
	return renderer;
}