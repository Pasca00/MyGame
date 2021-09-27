#pragma once

#include "Animation.h"
#include "ButtonView.h"
#include "../Input/InputCollector.h"

class InteractableView : public ButtonView {
	private:
		SDL_Rect* target;
		SDL_Rect proximity;

		Animation* promptAnimation;

		bool interacted;

		std::function<void()> onInteractListener;

	public:
		InteractableView(SDL_Rect* target, SDL_Texture* texture, SDL_Rect dstrect);

		void attachPromptAnimation(Animation* animation);
		bool targetIsInProximity();

		void setOnInteractListener(std::function<void()> onInteractListener);

		void onInteract(Input* input);

		void update();

		FrameView* getCurrectPromptFrame();
};

