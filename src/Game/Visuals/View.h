#pragma once

#include <SDL_image.h>

class View {
	public:
		SDL_Texture* texture;

		View(SDL_Renderer *renderer, const char* path);
		~View();
};

