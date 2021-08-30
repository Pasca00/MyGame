#include "FrameView.h"

FrameView::FrameView(SDL_Texture* texture, SDL_Rect dstrect, Uint32 timeOnScreen) : View(texture, dstrect) {
	this->timeOnScreen = timeOnScreen;
}