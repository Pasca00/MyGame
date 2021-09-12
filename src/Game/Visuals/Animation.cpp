#include "Animation.h"
#include "../Game.h"

Animation::Animation(std::vector<SDL_Texture*> textures, std::vector<SDL_Rect> dstrect, uint32_t frameTimes) {
	timeSinceLastFrame = 0;
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], dstrect[i], frameTimes));
	}
}

Animation::Animation(std::vector<SDL_Texture*> textures, SDL_Rect dstrect, std::vector<uint32_t> frameTimes) {
	timeSinceLastFrame = 0;
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], dstrect, frameTimes[i]));
	}
}

Animation::Animation(std::vector<SDL_Texture*> textures, SDL_Rect dstrect, uint32_t frameTimes) {
	timeSinceLastFrame = 0;
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], dstrect, frameTimes));
	}
}

void Animation::update() {
	if (Game::getInstance()->getCurrentTime() - timeSinceLastFrame >= frames->at(currentFrame)->timeOnScreen) {
		timeSinceLastFrame = Game::getInstance()->getCurrentTime();
		currentFrame++;
		currentFrame %= frames->size();
	}
}

FrameView* Animation::getCurrentFrame() {
	return frames->at(currentFrame);
}