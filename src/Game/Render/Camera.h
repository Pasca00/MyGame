#pragma once

#include "../Visuals/View.h"
#include "Renderer.h"

#define CAMERA_DIRECTION_LEFT -1
#define CAMERA_DIRECTION_RIGHT 1
#define CAMERA_DIRECTION_UP   -1
#define CAMERA_DIRECTION_DOWN  1
#define CAMERA_STATIONARY	   0

class Camera {
	private:	
		SDL_Rect rect;
		SDL_Rect *focusView;
		SDL_Rect focusZone;

		int xMinSpeed;
		int xRelativeSpeed;
		int newMaxDistance;

		int leftBound;
		int rightBound;

		int8_t xAxisDirection;
		int8_t yAxisDirection;

		Renderer* renderer;

	public:
		Camera();
		Camera(SDL_Rect* focusView, int leftBound, int rightBound);
		void setFocusView(SDL_Rect* focusView);

		bool viewIsOnScreen(View* view);
		void setDirection();
		void updateSpeed();
		void moveToFocus();

		void renderViewToRelativePosition(View* view);
		void renderViewToAbsolutePosition(View* view);

		int8_t getXDirection();

		SDL_Rect getRect();
		SDL_Rect getFocusZone();
};

