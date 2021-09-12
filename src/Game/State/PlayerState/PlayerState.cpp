#include "PlayerState.h"

PlayerState::PlayerState() { }

SDL_Texture* PlayerState::getCurrentTexture() {
	return animation->getCurrentFrame()->texture;
}

FrameView* PlayerState::getCurrentFrame() {
	return animation->getCurrentFrame();
}