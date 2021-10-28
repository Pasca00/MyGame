#pragma once

#include "PlayerState.h"

class Player;

class AttackPlayerState : public PlayerState {
	private:
		Player* player;

		Animation* firstAttackAnimation;

		Animation* secondAttackAnimation;
		int numberOfFramesSecondAttack;
		bool secondAttackRequested;

	public:
		AttackPlayerState(Player* player);

		void handleInput(Player* player, Input* input) override;
		void update() override;
		void draw() override;

		void resetAnimation() override;
};

