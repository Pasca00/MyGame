#include "InteractableView.h"
#include "../Input/InputCollector.h"

InteractableView::InteractableView(SDL_Rect* target, SDL_Texture* texture, SDL_Rect dstrect) : ButtonView(texture, dstrect) {
	this->target = target;
	this->interacted = false;
	this->promptAnimation = NULL;

	this->proximity.w = dstrect.w + 200;
	this->proximity.h = dstrect.h + 200;
	this->proximity.x = dstrect.x - 100;
	this->proximity.y = dstrect.y - 100;

	this->onInteractListener = [] {};
}

void InteractableView::attachPromptAnimation(Animation* animation) {
	SDL_Rect promptDstrect;
	SDL_QueryTexture(animation->getCurrentFrame()->texture, NULL, NULL, &(promptDstrect.w), &(promptDstrect.h));

	promptDstrect.y = dstrect.y - promptDstrect.h;
	promptDstrect.x = (dstrect.x + dstrect.x + dstrect.w - promptDstrect.w) / 2;
	printf("%d %d\n", promptDstrect.x, dstrect.x);

	animation->setRect(promptDstrect);

	this->promptAnimation = animation;
}

void InteractableView::setOnInteractListener(std::function<void()> onInteractListener) {
	this->onInteractListener = onInteractListener;
}

void InteractableView::onInteract(Input* input) {
	if (targetIsInProximity() && input->KEY_E && !interacted) {
		onInteractListener();
		interacted = true;
	}
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
	if (promptAnimation == NULL || interacted) {
		return NULL;
	}

	return promptAnimation->getCurrentFrame();
}
