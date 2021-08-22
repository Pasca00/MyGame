#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"


int main(int argc, char* args[]) {
	Game* game = NULL;
	game = game->getInstance();

	Uint32 oldTime = game->getCurrentTime(), deltaTime;
	double accumulator = 0;

	while (game->isRunning()) {
		Input input = game->collectInput();

		deltaTime = game->getCurrentTime() - oldTime;
		oldTime = game->getCurrentTime();
		accumulator += deltaTime;
		while (accumulator > 1.0/60.0) {
			game->handleInput(input);
			accumulator -= 1.0 / 60.0;
		}

		game->renderClearScreen();
		game->renderQueue();
	}

	return 0;
}
