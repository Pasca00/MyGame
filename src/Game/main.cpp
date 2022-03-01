#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"


int main(int argc, char* args[]) {
	Game* game = NULL;
	game = game->getInstance();

	Uint32 oldTime = game->getCurrentTime(), deltaTime;
	double accumulator = 0;

	Input input;

	

	while (game->isRunning()) {
		game->changeState();
		input = game->collectInput();

		deltaTime = game->getCurrentTime() - oldTime;
		oldTime = game->getCurrentTime();
		accumulator += deltaTime;
		while (accumulator > 1.0/60.0) {
			accumulator -= 1.0 / 60.0;
		}

		game->handleInput(input);
		game->update();
		game->renderClearScreen();
		game->renderQueue();

		SDL_GL_SwapWindow(game->getWindow()->getWindow());
	}

	return 0;
}
