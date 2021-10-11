#include "Animation.h"
#include "../Game.h"

Animation::Animation(std::vector<SDL_Texture*> textures, std::vector<SDL_Rect> dstrect, uint32_t frameTimes) {
	timeSinceLastFrame = 0;
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], dstrect[i], frameTimes));
	}

	this->timeMultiplier = new int(1);
}

Animation::Animation(std::vector<SDL_Texture*> textures, SDL_Rect dstrect, std::vector<uint32_t> frameTimes) {
	timeSinceLastFrame = 0;
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], dstrect, frameTimes[i]));
	}

	this->timeMultiplier = new int(1);
}

Animation::Animation(std::vector<SDL_Texture*> textures, SDL_Rect dstrect, uint32_t frameTimes) {
	timeSinceLastFrame = 0;
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], dstrect, frameTimes));
	}

	this->timeMultiplier = new int(1);
}

void Animation::setRect(SDL_Rect dstrect) {
	for (int i = 0; i < frames->size(); i++) {
		(*frames)[i]->dstrect = dstrect;
	}
}

void Animation::setTimeMultiplier(int* timeMultiplier) {
	delete this->timeMultiplier;
	this->timeMultiplier = timeMultiplier;
}

void Animation::update() {
	if (Game::getInstance()->getCurrentTime() - timeSinceLastFrame >= frames->at(currentFrame)->timeOnScreen * (*timeMultiplier)) {
		timeSinceLastFrame = Game::getInstance()->getCurrentTime();
		currentFrame++;
		currentFrame %= frames->size();
	}
}

FrameView* Animation::getCurrentFrame() {
	return frames->at(currentFrame);
}