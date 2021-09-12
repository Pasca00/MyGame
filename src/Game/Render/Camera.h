#pragma once

#include "../Visuals/View.h"

class Camera {
	private:
		SDL_Rect dimensions;
		SDL_Rect* focusView;
		SDL_Rect focusZone;

	public:
		Camera();
		Camera(SDL_Rect* focusView);
		void setFocusView(SDL_Rect* focusView);
};

