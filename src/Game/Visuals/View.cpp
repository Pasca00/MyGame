#include "View.h"
#include "../Render/Camera.h"

View::View() { }

View::View(Texture* texture, Hitbox* hitbox) {
	this->texture = texture;
	this->hitbox = hitbox;
	sizeMultiplier = 1;
}

View::View(Texture* texture, float x, float y, float sizeMultiplier) {
	this->texture = texture;
	
	this->sizeMultiplier = sizeMultiplier;
	this->hitbox = new Hitbox(x, y, texture->getWidth() * sizeMultiplier, texture->getHeight() * sizeMultiplier);
}

View::~View() {
	//SDL_DestroyTexture(texture);
}

void View::draw(Camera* camera) {
	camera->drawViewToRelativePosition(this);
}