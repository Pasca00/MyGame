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

Camera::Camera(SDL_Rect* focusView, int leftBound, int rightBound) {
	rect.w = Window::BASE_WINDOW_WIDTH;
	rect.h = Window::BASE_WINDOW_HEIGHT;
	rect.x = rect.y = 0;

	focusZone.w = 250;
	focusZone.h = 250;
	focusZone.x = (rect.w - focusZone.w) / 2;
	focusZone.y = (rect.h - focusZone.h) / 2;

	this->focusView = focusView;

	xSpeed = 6;

	this->leftBound = leftBound;
	this->rightBound = rightBound;

	xAxisDirection = CAMERA_STATIONARY;
	yAxisDirection = CAMERA_STATIONARY;

	renderer = Game::getInstance()->getRenderer();
}

void Camera::setFocusView(SDL_Rect* focusView) {
	if (this->focusView != focusView) {
		this->focusView = focusView;

		focusZone.w = 250;
		focusZone.h = 250;
		focusZone.x = (rect.w - focusZone.w) / 2 + rect.x;
		focusZone.y = (rect.h - focusZone.h) / 2 + rect.y;
	}
}

bool Camera::viewIsOnScreen(View* view) {
	if (view == NULL) {
		return false;
	}

	if (view->dstrect.x + view->dstrect.w >= rect.x && view->dstrect.x < rect.x + rect.w
		&& view->dstrect.y >= rect.y && view->dstrect.y < rect.y + rect.h) {
		return true;
	}

	return false;
}

void Camera::setDirection() {
	if (focusView->x < focusZone.x) {
		if (rect.x == leftBound) {
			xAxisDirection = CAMERA_STATIONARY;
		} else {
			xAxisDirection = CAMERA_DIRECTION_LEFT;
		}

		return;
	}

	if (focusView->x + focusView->w >= focusZone.x + focusZone.w) {
		if (rect.x == rightBound - rect.w) {
			xAxisDirection = CAMERA_STATIONARY;
		} else {
			xAxisDirection = CAMERA_DIRECTION_RIGHT;
		}

		return;
	}

	xAxisDirection = CAMERA_STATIONARY;
}

void Camera::moveToFocus() {
	setDirection();

	if (rect.x + xSpeed * xAxisDirection < leftBound) {
		rect.x = leftBound;
		focusZone.x = rect.x + (rect.w - focusZone.w) / 2;
		return;
	} else if (rect.x + rect.w + xSpeed * xAxisDirection >= rightBound) {
		rect.x = rightBound - rect.w;
		focusZone.x = rect.x + (rect.w - focusZone.w) / 2;
		return;
	}

	rect.x += xSpeed * xAxisDirection;
	focusZone.x += xSpeed * xAxisDirection;

	if (xAxisDirection == DIRECTION_LEFT) {
		if (focusZone.x < focusView->x) {
			int delta = focusView->x - focusZone.x;
			focusZone.x += delta;
			rect.x += delta;
		}
	} else if (xAxisDirection == DIRECTION_RIGHT) {
		if (focusZone.x + focusZone.w > focusView->x + focusView->w) {
			int delta = focusZone.x + focusZone.w - focusView->x - focusView->w - 1;
			focusZone.x -= delta;
			rect.x -= delta;
		}
	}
}

void Camera::renderViewToRelativePosition(View* view) {
	if (viewIsOnScreen(view) && view != NULL) {
		SDL_Rect rendRect = view->dstrect;
		rendRect.x -= rect.x;
		renderer->addToQueue(rendRect, view->texture);
	}
}

int8_t Camera::getXDirection() {
	return xAxisDirection;
}

SDL_Rect Camera::getRect() {
	return rect;
}

SDL_Rect Camera::getFocusZone() {
	return focusZone;
}