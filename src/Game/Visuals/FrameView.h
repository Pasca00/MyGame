#pragma once

#include "View.h"

class FrameView : public View{

	public:
		Uint32 timeOnScreen;

		FrameView(SDL_Texture* texture, SDL_Rect dstrect, Uint32 timeOnScreen);
};

