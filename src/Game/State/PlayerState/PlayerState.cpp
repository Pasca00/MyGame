#include "PlayerState.h"

PlayerState::PlayerState() {
	numberOfFrames = 0;
	animation = NULL;
}

void PlayerState::resetAnimation() {
	animation->reset();
}

SDL_Texture* PlayerState::getCurrentTexture() {
	return animation->getCurrentFrame()->texture;
}

FrameView* PlayerState::getCurrentFrame() {
	return animation->getCurrentFrame();
}