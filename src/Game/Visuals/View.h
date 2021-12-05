#pragma once

#include <SDL_image.h>
#include "Core/Texture.h"
#include "../glm/glm.hpp"

class Camera;

class View {
	public:
		int sizeMultiplier;
		Texture* texture;
		SDL_Rect dstrect;
		glm::vec3 pos;

		View();
		View(Texture* texture, SDL_Rect destrect);
		View(Texture* texture, float x, float y, float sizeMultiplier = 1.f);

		~View();

		void draw(Camera* camera);
};

