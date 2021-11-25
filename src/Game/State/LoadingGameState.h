#pragma once
#include "../Render/Renderer.h"
#include "GameState.h"
#include "PlayingGameState.h"
#include "../Visuals/Animation.h"

class LoadingGameState : public GameState {
	private:
		Animation* loadingAnimation;

		std::thread loaderThread;
		PlayingGameState* s_;
		bool loaderIsReady;

		std::mutex m;

	public:
		LoadingGameState(Renderer* renderer);

		void enter(/*should take level that needs to be loaded*/);

		void handleInput(Game* game, Input* input) override;
		void update() override;
		void draw() override;
};

