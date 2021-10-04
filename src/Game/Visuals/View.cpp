#include "View.h"
#include "../Render/Camera.h"

View::View(SDL_Texture* texture, SDL_Rect dstrect) {
	this->texture = texture;
	this->dstrect = dstrect;
}

View::~View() {
	//SDL_DestroyTexture(texture);
}

void View::draw(Camera* camera) {
	camera->renderViewToRelativePosition(this);
}