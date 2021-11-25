#pragma once

#include <SDL_image.h>

class Camera;

class View {
	public:
		int sizeMultiplier;
		SDL_Texture* texture;
		SDL_Rect dstrect;

		View();
		View(SDL_Texture* texture, SDL_Rect destrect);
		View(SDL_Texture* texture, int x, int y, float sizeMultiplier);

		~View();

		void draw(Camera* camera);
};

