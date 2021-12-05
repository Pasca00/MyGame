#include "Filter.h"
#include "../Render/Camera.h"

Filter::Filter(Texture* texture, SDL_BlendMode mode) {
	this->texture = texture;

	this->alphaValue = 0;
	this->alphaStep = 20;
	this->fade = FADE_NULL;
	this->isActive = false;

	//SDL_SetTextureBlendMode(texture, mode);
	//SDL_SetTextureAlphaMod(texture, alphaValue);

	SDL_Rect dstrect = { 0, 0, Window::BASE_WINDOW_WIDTH, Window::BASE_WINDOW_HEIGHT};
	this->dstrect = dstrect;
}

void Filter::fadeIn() {
	isActive = true;
	fade = FADE_IN;
}

void Filter::fadeOut() {
	fade = FADE_OUT;
}

void Filter::setFadeType(Uint8 fadeType) {
	this->fade = fadeType;
}

void Filter::draw(Camera* camera) {
	if (!isActive) {
		return;
	}

	if (fade == FADE_IN) {
		if (alphaValue + alphaStep > 255) {
			alphaValue = 255;
			fade = FADE_NULL;
		}
		else {
			alphaValue += alphaStep;
		}

		//SDL_SetTextureAlphaMod(texture, alphaValue);
	} else if (fade == FADE_OUT) {
		if (alphaValue < alphaStep) {
			alphaValue = 0;
			fade = FADE_NULL;
			isActive = false;
		}
		else {
			alphaValue -= alphaStep;
		}

		//SDL_SetTextureAlphaMod(texture, alphaValue);
	}
	
	camera->renderViewToAbsolutePosition(this);
}