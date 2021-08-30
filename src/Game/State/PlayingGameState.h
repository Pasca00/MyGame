#pragma once

#include <vector>
#include <thread>

#include "GameState.h"
#include "../Player/Player.h"
#include "../Visuals/View.h"

class PlayingGameState : public GameState {
	private:
		View* background;
		std::vector<View*> treesFar;
		std::vector<View*> treesClose;

		Player* player;

	public:
		PlayingGameState();

		void handleInput(Game* game, Input* input);
		void update();
		void draw();
};

