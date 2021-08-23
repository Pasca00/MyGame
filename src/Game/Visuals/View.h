#pragma once

#include <SDL_image.h>

class View {
	public:
		SDL_Texture* texture;
		SDL_Rect dstrect;

		View(SDL_Texture* texture, SDL_Rect destrect);
		~View();
};

