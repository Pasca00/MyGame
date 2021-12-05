#include "Animation.h"
#include "../Game.h"

Animation::Animation(std::vector<Texture*> textures, std::vector<SDL_Rect> dstrect, uint32_t frameTimes) {
	timeSinceLastFrame = Game::getInstance()->getCurrentTime();
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], dstrect[i], frameTimes));
	}

	this->timeMultiplier = new int(1);

	done = false;
}

Animation::Animation(std::vector<Texture*> textures, std::vector<uint32_t> frameTimes, float x, float y, float sizeMultiplier) {
	timeSinceLastFrame = 0;
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], frameTimes[i], x, y, sizeMultiplier));
	}

	this->timeMultiplier = new int(1);

	done = false;
}

Animation::Animation(std::vector<Texture*> textures, uint32_t frameTimes, float x, float y, float sizeMultiplier) {
	timeSinceLastFrame = 0;
	currentFrame = 0;
	frames = new std::vector<FrameView*>(textures.size(), NULL);
	for (int i = 0; i < textures.size(); i++) {
		(*frames)[i] = (new FrameView(textures[i], frameTimes, x, y, sizeMultiplier));
	}

	this->timeMultiplier = new int(1);

	done = false;
}

void Animation::setRect(SDL_Rect dstrect) {
	for (int i = 0; i < frames->size(); i++) {
		(*frames)[i]->dstrect = dstrect;
	}
}

void Animation::reset() {
	timeSinceLastFrame = Game::getInstance()->getCurrentTime();
	currentFrame = 0;
	done = false;
}

bool Animation::isDone() {
	return done;
}

void Animation::setTimeMultiplier(int* timeMultiplier) {
	delete this->timeMultiplier;
	this->timeMultiplier = timeMultiplier;
}

void Animation::update() {
	if (Game::getInstance()->getCurrentTime() - timeSinceLastFrame >= frames->at(currentFrame)->timeOnScreen * (*timeMultiplier)) {
		timeSinceLastFrame = Game::getInstance()->getCurrentTime();
		currentFrame++;
		
		if (currentFrame == frames->size()) {
			currentFrame = 0;
			done = true;
		}
	}
}

int Animation::getSize() {
	return frames->size();
}

int Animation::getCurrentFrameIndex() {
	return currentFrame;
}

FrameView* Animation::getCurrentFrame() {
	return frames->at(currentFrame);
}