#pragma once

#include "View.h"

#define FADE_IN 1
#define FADE_OUT 2
#define FADE_NULL 3

class Filter : public View {
	private:
		bool isActive;
		
		Uint8 fade;

		Uint8 alphaStep;
		Uint8 alphaValue;

	public:
		Filter(SDL_Texture* texture, SDL_Rect rect, SDL_BlendMode mode);

		void draw(Camera* camera);

		void setFadeType(Uint8 fadeType);

		void fadeIn();
		void fadeOut();
};