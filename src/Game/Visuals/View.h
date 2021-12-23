#pragma once

#include <SDL_image.h>
#include "../Physics/Hitbox.h"
#include "Core/Texture.h"
#include "../glm/glm.hpp"

class Camera;

class View {
	public:
		int sizeMultiplier;
		Texture* texture;
		Hitbox* hitbox;

		View();
		View(Texture* texture, Hitbox* hitbox);
		View(Texture* texture, float x, float y, float sizeMultiplier = 1.f);

		~View();

		void draw(Camera* camera);
};

