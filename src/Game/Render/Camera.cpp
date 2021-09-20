#include "Camera.h"
#include "../Window/Window.h"

#include "../Game.h"

Camera::Camera() {
	rect.w = Window::BASE_WINDOW_WIDTH;
	rect.h = Window::BASE_WINDOW_HEIGHT;
	rect.x = rect.y = 0;

	focusZone.w = 500;
	focusZone.h = 500;
	focusZone.x = (rect.w - focusZone.w) / 2;
	focusZone.y = (rect.h - focusZone.h) / 2;

	SDL_memset(&focusView, 0, sizeof(SDL_Rect));

	xSpeed = 15;

	xAxisDirection = CAMERA_STATIONARY;
	yAxisDirection = CAMERA_STATIONARY;

	renderer = Game::getInstance()->getRenderer();
}

Camera::Camera(SDL_Rect* focusView) {
	rect.w = Window::BASE_WINDOW_WIDTH;
	rect.h = Window::BASE_WINDOW_HEIGHT;
	rect.x = rect.y = 0;

	focusZone.w = 200;
	focusZone.h = 200;
	focusZone.x = (rect.w - focusZone.w) / 2;
	focusZone.y = (rect.h - focusZone.h) / 2;

	this->focusView = focusView;

	xSpeed = 5;

	xAxisDirection = CAMERA_STATIONARY;
	yAxisDirection = CAMERA_STATIONARY;

	renderer = Game::getInstance()->getRenderer();
}

void Camera::setFocusView(SDL_Rect* focusView) {
	this->focusView = focusView;

	focusZone.w = focusView->w * 3;
	focusZone.h = focusView->h * 3;
	focusZone.x = (rect.w - focusZone.w) / 2;
	focusZone.y = (rect.h - focusZone.h) / 2;
}

bool Camera::viewIsOnScreen(View* view) {
	if (view->dstrect.x >= rect.x && view->dstrect.x < rect.x + rect.w
		&& view->dstrect.y >= rect.y && view->dstrect.y < rect.y + rect.h) {
		return true;
	}

	return false;
}

void Camera::setDirection() {
	if (focusView->x < focusZone.x) {
		xAxisDirection = CAMERA_DIRECTION_LEFT;
		return;
	}

	if (focusView->x >= focusZone.x + focusZone.w) {
		xAxisDirection = CAMERA_DIRECTION_RIGHT;
		return;
	}

	xAxisDirection = CAMERA_STATIONARY;
}

void Camera::moveToFocus() {
	setDirection();
	rect.x += xSpeed * xAxisDirection;
	focusZone.x += xSpeed * xAxisDirection;
}

void Camera::renderViewToRelativePosition(View* view) {
	SDL_Rect rendRect = view->dstrect;
	rendRect.x -= rect.x;
	renderer->addToQueue(rendRect, view->texture);
}

int8_t Camera::getXDirection() {
	return xAxisDirection;
}

SDL_Rect Camera::getRect() {
	return rect;
}