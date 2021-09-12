#pragma once

#include "PlayerState.h"

class WalkingPlayerState : public PlayerState {
	private:
		Player* player;

	public:
		WalkingPlayerState(Player* player);

		void handleInput(Player* player, Input* input) override;
		void update() override;
		void draw() override;
};

