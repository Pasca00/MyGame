#include "ButtonView.h"

ButtonView::ButtonView(Texture *texture, SDL_Rect dstrect) : View(texture, dstrect) {
	onHoverListener = NULL;
	onHoverReleaseListener = NULL;

	onClickListener = NULL;
}

ButtonView::ButtonView(Texture* texture, int x, int y, int sizeMultiplier)
	: View(texture, x, y, sizeMultiplier) {
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
	if ((float)x >= pos.x && (float)x <= pos.x + texture->width * sizeMultiplier && (float)y >= pos.y && (float)y <= pos.y + texture->height * sizeMultiplier) {
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

