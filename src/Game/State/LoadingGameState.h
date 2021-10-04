#pragma once
#include "../Render/Renderer.h"
#include "GameState.h"
#include "PlayingGameState.h"
#include "../Visuals/Animation.h"

class LoadingGameState : public GameState {
	private:
		Animation* loadingAnimation;

		std::thread loaderThread;
		std::atomic<PlayingGameState*> s_;
		std::atomic<bool> loaderIsReady;

	public:
		LoadingGameState(Renderer* renderer);

		void enter(/*should take level that needs to be loaded*/);

		void handleInput(Game* game, Input* input) override;
		void update() override;
		void draw() override;
};

