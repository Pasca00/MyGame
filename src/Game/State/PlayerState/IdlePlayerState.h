#pragma once

#include "PlayerState.h"

class IdlePlayerState : public PlayerState {
	private:

	public:
		IdlePlayerState();

		void handleInput(Player* player, Input* input) override;
		void update() override;
		void draw() override;
};

