#include "View.h"
#include "../Render/Camera.h"

View::View() { }

View::View(Texture* texture, SDL_Rect dstrect) {
	this->texture = texture;
	this->dstrect = dstrect;
	sizeMultiplier = 1;
}

View::View(Texture* texture, float x, float y, float sizeMultiplier) {
	this->texture = texture;
	
	this->sizeMultiplier = sizeMultiplier;
	this->pos = glm::vec3(x, y, 0.f);
}

View::~View() {
	//SDL_DestroyTexture(texture);
}

void View::draw(Camera* camera) {
	camera->drawViewToRelativePosition(this);
}