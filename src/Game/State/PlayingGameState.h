#pragma once

#include <vector>
#include <thread>

#include "GameState.h"
#include "../Level/Level.h"

class PlayingGameState : public GameState {
	private:
		Level* level;

	public:
		PlayingGameState();

		void handleInput(Game* game, Input* input);
		void enter() override;
		void update();
		void draw();
};

