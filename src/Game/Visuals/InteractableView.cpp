#include "InteractableView.h"

InteractableView::InteractableView(SDL_Rect* target, SDL_Texture* texture, SDL_Rect dstrect) : View(texture, dstrect) {
	this->target = target;
	this->interacted = false;
	this->promptAnimation = NULL;

	this->proximity.w = dstrect.w + 200;
	this->proximity.h = dstrect.h + 200;
	this->proximity.x = dstrect.x - 100;
	this->proximity.y = dstrect.y - 100;
}

void InteractableView::attachAnimation(Animation* animation) {
	this->promptAnimation = animation;
}

bool InteractableView::targetIsInProximity() {
	if ((target->x + target->w >= proximity.x && target->x + target->w < proximity.x + proximity.w)
		|| (target->x < proximity.x + proximity.w && target->x >= proximity.x)) {
		return true;
	}

	return false;
}

void InteractableView::update() {
	if (promptAnimation != NULL && !interacted) {
		promptAnimation->update();
	}
}

FrameView* InteractableView::getCurrectPromptFrame() {
	if (promptAnimation == NULL) {
		return NULL;
	}

	return promptAnimation->getCurrentFrame();
}
