#include "Camera.h"
#include "../Window/Window.h"

Camera::Camera() {
	dimensions.w = Window::BASE_WINDOW_WIDTH;
	dimensions.h = Window::BASE_WINDOW_HEIGHT;
	dimensions.x = dimensions.y = 0;

	focusZone.w = 200;
	focusZone.h = 200;
	focusZone.x = (dimensions.w - focusZone.w) / 2;
	focusZone.y = (dimensions.h - focusZone.h) / 2;

	focusView = NULL;
}

Camera::Camera(SDL_Rect* focusView) {
	dimensions.w = Window::BASE_WINDOW_WIDTH;
	dimensions.h = Window::BASE_WINDOW_HEIGHT;
	dimensions.x = dimensions.y = 0;

	this->focusView = focusView;

	focusZone.w = focusView->w * 2;
	focusZone.h = focusView->h * 2;
	focusZone.x = (dimensions.w - focusZone.w) / 2;
	focusZone.y = (dimensions.h - focusZone.h) / 2;
}

void Camera::setFocusView(SDL_Rect* focusView) {
	this->focusView = focusView;

	focusZone.w = focusView->w * 2;
	focusZone.h = focusView->h * 2;
	focusZone.x = (dimensions.w - focusZone.w) / 2;
	focusZone.y = (dimensions.h - focusZone.h) / 2;
}