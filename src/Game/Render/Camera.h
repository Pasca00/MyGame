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
		Hitbox* rect;
		Hitbox* focusView;
		Hitbox* focusZone;

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
		Camera(Hitbox* focusView, int leftBound, int rightBound);
		void setFocusView(Hitbox* focusView);

		bool viewIsOnScreen(View* view);
		void setDirection();
		void updateSpeed();
		void moveToFocus();

		void renderViewToRelativePosition(View* view);
		void renderViewToAbsolutePosition(View* view);

		void drawViewToRelativePosition(View* view, Shader* shader = NULL);
		void drawViewToRelativePosition(Player* player, Shader* shader = NULL);

		int8_t getXDirection();

		Hitbox* getRect();
		Hitbox* getFocusZone();
};

