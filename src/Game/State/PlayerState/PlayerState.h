#pragma once

#include "../../Input/InputCollector.h"
#include "../../Visuals/Animation.h"

class Player;

class PlayerState {
	protected:
		Uint8 numberOfFrames;
		Animation* animation;

	public:
		PlayerState();

		virtual void handleInput(Player* player, Input* input) = 0;
		virtual void update() = 0;
		virtual void draw() = 0;

		virtual void resetAnimation();

		FrameView* getCurrentFrame();
		Texture* getCurrentTexture();
};

