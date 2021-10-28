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
		Animation(std::vector<SDL_Texture*> textures, std::vector<SDL_Rect> dstrect, uint32_t frameTimes);
		Animation(std::vector<SDL_Texture*> textures, SDL_Rect dstrect, std::vector<uint32_t> frameTimes);
		Animation(std::vector<SDL_Texture*> textures, SDL_Rect dstrect, uint32_t frameTimes);

		void setRect(SDL_Rect dstrect);

		void reset();

		bool isDone();

		void setTimeMultiplier(int* timeMultiplier);

		FrameView* getCurrentFrame();
		int getCurrentFrameIndex();
		int getSize();

		void update();
};

