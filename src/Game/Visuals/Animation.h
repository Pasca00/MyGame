#pragma once

#include <vector>
#include <string>

#include "FrameView.h"

class Animation {
	private:
		uint8_t currentFrame;
		std::vector<FrameView*>* frames;
		uint32_t timeSinceLastFrame;

		int* timeMultiplier;

		bool done;

	public:
		Animation(std::vector<Texture*> textures, std::vector<SDL_Rect> dstrect, uint32_t frameTimes);
		Animation(std::vector<Texture*> textures, std::vector<uint32_t> frameTimes, float x, float y, float sizeMultiplier = 1.f);
		Animation(std::vector<Texture*> textures, uint32_t frameTimes, float x, float y, float sizeMultiplier = 1.f);

		void setRect(SDL_Rect dstrect);
		void setPosition(float x, float y);

		void reset();

		bool isDone();

		void setTimeMultiplier(int* timeMultiplier);

		FrameView* getCurrentFrame();
		int getCurrentFrameIndex();
		int getSize();

		void update();
};

