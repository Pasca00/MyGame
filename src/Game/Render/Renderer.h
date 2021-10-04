#pragma once

#include <vector>
//#include <SDL.h>

#include "../Window/Window.h"
#include "../Visuals/View.h"
#include "../Player/Player.h"

class Renderer {
	private:
		SDL_Renderer* renderer;
		std::vector<SDL_Texture*> queue;
		Uint8 drawR;
		Uint8 drawG;
		Uint8 drawB;

	public:
		Renderer(Window* window);

		void addToQueueFlipped(SDL_Rect dstrect, SDL_Texture* texture, SDL_RendererFlip flipType);

		void addToQueue(SDL_Rect dstrect, SDL_Texture* texture);
		void addToQueue(View* view);
		void addToQueue(Player* player);

		void clearScreen();
		void renderQueue();

		SDL_Renderer* getSDLRenderer();
};

