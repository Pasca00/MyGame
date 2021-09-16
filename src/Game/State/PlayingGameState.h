#pragma once

#include <vector>
#include <thread>

#include "GameState.h"
#include "../Render/Camera.h"
#include "../Player/Player.h"
#include "../Visuals/View.h"
#include "../Visuals/Animation.h"
#include "../Visuals/Background.h"

class PhysicsEngine;

class PlayingGameState : public GameState {
	private:
		Camera* camera;
		Player* player;
		PhysicsEngine* physicsEngine;

		Background* background;

		std::vector<View*> tiles;

	public:
		PlayingGameState();

		void handleInput(Game* game, Input* input);
		void enter() override;
		void update();
		void draw();
};

