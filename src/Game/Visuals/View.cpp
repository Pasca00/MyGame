#include "View.h"
#include "../Render/Camera.h"

View::View() { }

View::View(SDL_Texture* texture, SDL_Rect dstrect) {
	this->texture = texture;
	this->dstrect = dstrect;
	sizeMultiplier = 1;
}

View::View(SDL_Texture* texture, int x, int y, float sizeMultiplier) {
	this->texture = texture;
	
	this->sizeMultiplier = sizeMultiplier;
	this->dstrect.x = x;
	this->dstrect.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h);
	this->dstrect.w *= sizeMultiplier;
	this->dstrect.h *= sizeMultiplier;
}

View::~View() {
	//SDL_DestroyTexture(texture);
}

void View::draw(Camera* camera) {
	camera->renderViewToRelativePosition(this);
}