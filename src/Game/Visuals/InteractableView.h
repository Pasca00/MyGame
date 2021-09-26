#pragma once

#include "Animation.h"

class InteractableView : public View {
	private:
		SDL_Rect* target;
		SDL_Rect proximity;

		Animation* promptAnimation;

		bool interacted;

	public:
		InteractableView(SDL_Rect* target, SDL_Texture* texture, SDL_Rect dstrect);

		void attachAnimation(Animation* animation);
		bool targetIsInProximity();

		void update();

		FrameView* getCurrectPromptFrame();
};

