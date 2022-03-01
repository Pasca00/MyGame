#pragma once

#include "Animation.h"
#include "ButtonView.h"
#include "../Input/InputCollector.h"

class InteractableView : public View {
	private:
		glm::vec3* target;
		glm::vec3 proximity;
		glm::vec3 proximity2;

		Animation* promptAnimation;

		bool interacted;

		std::function<void()> onInteractListener;

	public:
		InteractableView(Texture* texture, float x, float y, float sizeMultiplier = 1);

		void attachPromptAnimation();
		bool targetIsInProximity();

		void setOnInteractListener(std::function<void()> onInteractListener);

		void onInteract(Input* input);

		void draw(Camera* camera);
		void update();

		FrameView* getCurrectPromptFrame();
};

