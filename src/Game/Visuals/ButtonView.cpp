#include "ButtonView.h"

ButtonView::ButtonView(SDL_Texture *texture, SDL_Rect dstrect) : View(texture, dstrect) {
	onHoverListener = NULL;
	onHoverReleaseListener = NULL;

	onClickListener = NULL;
}

void ButtonView::setOnHoverListener(std::function<void()> onHoverListener, std::function<void()> onHoverReleaseListener) {
	this->onHoverListener = onHoverListener;
	this->onHoverReleaseListener = onHoverReleaseListener;
}

void ButtonView::setOnClickListener(std::function<void()> onClickListener) {
	this->onClickListener = onClickListener;
}

bool ButtonView::hasHoverListener() {
	return onHoverListener != NULL;
}

bool ButtonView::hasClickListener() {
	return onClickListener != NULL;
}

bool ButtonView::mouseIsHovering(int x, int y) {
	if (x >= dstrect.x && x <= dstrect.x + dstrect.w && y >= dstrect.y && y <= dstrect.y + dstrect.h) {
		return true;
	}

	return false;
}

void ButtonView::onHover() {
	onHoverListener();
}

void ButtonView::onHoverRelease() {
	onHoverReleaseListener();
}

void ButtonView::onClick() {
	onClickListener();
}

