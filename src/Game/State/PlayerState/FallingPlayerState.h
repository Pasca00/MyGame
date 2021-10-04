#pragma once

#include "PlayerState.h"

class FallingPlayerState : public PlayerState {
	private:


	public:
		FallingPlayerState();

		void handleInput(Player* player, Input* input);
		void update();
		void draw();
};

