#pragma once

#include <vector>
#include <SDL.h>
#include "../Window/Window.h"

class Renderer {
	private:
		SDL_Renderer* renderer;
		std::vector<SDL_Texture*> queue;
		Uint8 drawR;
		Uint8 drawG;
		Uint8 drawB;

	public:
		Renderer(Window* window);
		void addToQueue(SDL_Texture* texture);
		void clearScreen();
		void renderQueue();

		void updateColors();

		SDL_Renderer* getSDLRenderer();
};

