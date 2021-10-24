#include "Camera.h"
#include "../Window/Window.h"

#include "../Game.h"

int min(int a1, int a2) {
	return (a1 < a2) ? a1 : a2;
}

int max(int a1, int a2) {
	return (a1 > a2) ? a1 : a2;
}

Camera::Camera() {
	rect.w = Window::BASE_WINDOW_WIDTH;
	rect.h = Window::BASE_WINDOW_HEIGHT;
	rect.x = rect.y = 0;

	focusZone.w = 500;
	focusZone.h = 500;
	focusZone.x = (rect.w - focusZone.w) / 2;
	focusZone.y = (rect.h - focusZone.h) / 2;

	SDL_memset(&focusView, 0, sizeof(SDL_Rect));

	xMinSpeed = 15;

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

	xMinSpeed = 15;
	xRelativeSpeed = 0;

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
		//focusZone.x = (rect.w - focusZone.w - camera.x) / 2 + rect.x;
		//focusZone.y = (rect.h - focusZone.h - camera.y) / 2 + rect.y;

		if (xAxisDirection == DIRECTION_LEFT) {
			newMaxDistance = focusZone.x - focusView->x;
		}
		else if (xAxisDirection == DIRECTION_RIGHT) {
			newMaxDistance = focusZone.x + focusZone.x - focusView->x - focusView->w;
		}
		else {
			newMaxDistance = 0;
		}
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

	if (focusView->x + focusView->w > focusZone.x + focusZone.w) {
		if (rect.x + rect.w == rightBound) {
			xAxisDirection = CAMERA_STATIONARY;
		} else {
			xAxisDirection = CAMERA_DIRECTION_RIGHT;
		}

		return;
	}

	xAxisDirection = CAMERA_STATIONARY;
}

void Camera::updateSpeed() {
	long d;
	if (xAxisDirection == DIRECTION_LEFT) {
		d = focusZone.x - focusView->x;
	} else if (xAxisDirection == DIRECTION_RIGHT) {
		d = focusZone.x + focusZone.x - focusView->x - focusView->w;
	} else {
		d = 0;
	}
	
	// TODO: newMaxDistance is always 0 because of the way the focusZone's coordinates
	//		 are calculated.
	xMinSpeed = max(7, min(20, (-1.0f/newMaxDistance) * d * d + 100 * d - 500));
}

void Camera::moveToFocus() {
	setDirection();
	//updateSpeed();

	if (rect.x + xMinSpeed * xAxisDirection < leftBound) {
		rect.x = leftBound;
		focusZone.x = rect.x + (rect.w - focusZone.w) / 2;
		return;
	} else if (rect.x + rect.w + xMinSpeed * xAxisDirection >= rightBound) {
		rect.x = rightBound - rect.w;
		focusZone.x = rect.x + (rect.w - focusZone.w) / 2;
		return;
	}

	if (xAxisDirection == DIRECTION_LEFT) {
		if (focusZone.x + xMinSpeed * xAxisDirection < focusView->x) {
			int dist = focusZone.x - focusView->x;
			focusZone.x -= dist;
			rect.x -= dist;
		} else {
			focusZone.x += xMinSpeed * xAxisDirection;
			rect.x += xMinSpeed * xAxisDirection;
		}
	} else if (xAxisDirection == DIRECTION_RIGHT) {
		if (focusZone.x + focusZone.w + xMinSpeed * xAxisDirection > focusView->x + focusView->w) {
			int dist = focusView->x + focusView->w - (focusZone.x + focusZone.w);
			focusZone.x += dist;
			rect.x += dist;
		} else {
			focusZone.x += xMinSpeed * xAxisDirection;
			rect.x += xMinSpeed * xAxisDirection;
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

void Camera::renderViewToAbsolutePosition(View* view) {
	renderer->addToQueue(view);
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