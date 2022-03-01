#pragma once

#include "View.h"

class FrameView : public View {
	public:
		Uint32 timeOnScreen;

		FrameView(Texture* texture, Hitbox* hitbox, Uint32 timeOnScreen);
		FrameView(Texture* texture, Uint32 timeOnScreen, float x, float y, float sizeMultiplier = 1.f);
};

