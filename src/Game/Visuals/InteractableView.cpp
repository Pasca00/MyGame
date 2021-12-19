#include "InteractableView.h"
#include "../Input/InputCollector.h"
#include "../Render/Camera.h"
#include "TextureBag/TextureBag.h"

InteractableView::InteractableView(Texture* texture, float x, float y, float sizeMultiplier) 
	: View(texture, x, y, sizeMultiplier) {

	this->target = new glm::vec3(0, 0, 1);
	this->interacted = false;
	this->promptAnimation = NULL;

	attachPromptAnimation();
}

void InteractableView::attachPromptAnimation() {
	std::vector<Texture*> eKeys{
		TextureBag::getInstance()->miniTextures["eKeyUp"],
		TextureBag::getInstance()->miniTextures["eKeyDown"]
	};

	float x = pos.x + texture->getWidth() * sizeMultiplier / 2;
	float y = pos.y + texture->getHeight() * sizeMultiplier;

	this->promptAnimation = new Animation(eKeys, 300, x, y);
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
	/*if ((target->x + target->w >= proximity.x && target->x + target->w < proximity.x + proximity.w)
		|| (target->x < proximity.x + proximity.w && target->x >= proximity.x)) {
		return true;
	}*/

	return true;
}

void InteractableView::draw(Camera* camera) {
	camera->drawViewToRelativePosition(this);
	if (targetIsInProximity() && !interacted && promptAnimation != NULL) {
		promptAnimation->getCurrentFrame()->draw(camera);
	}
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
