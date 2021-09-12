#pragma once

#include <vector>
#include <thread>

#include "GameState.h"
#include "../Render/Camera.h"
#include "../Player/Player.h"
#include "../Visuals/View.h"
#include "../Visuals/Animation.h"

class PlayingGameState : public GameState {
	private:
		Camera* camera;
		Player* player;

		View* background;
		std::vector<View*> treesFar;
		std::vector<View*> treesClose;

		View* test;

	public:
		PlayingGameState();

		void handleInput(Game* game, Input* input);
		void enter() override;
		void update();
		void draw();
};

