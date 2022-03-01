#include "FrameView.h"

FrameView::FrameView(Texture* texture, Hitbox* hitbox, Uint32 timeOnScreen) 
	: View(texture, hitbox) {
	this->timeOnScreen = timeOnScreen;
}

FrameView::FrameView(Texture* texture, Uint32 timeOnScreen, float x, float y, float sizeMultiplier)
	: View(texture, x, y, sizeMultiplier){
	this->timeOnScreen = timeOnScreen;
}