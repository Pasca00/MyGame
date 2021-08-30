#pragma once
#include "../Render/Renderer.h"
#include "GameState.h"
#include "PlayingGameState.h"
#include "../Visuals/Animation.h"

class LoadingGameState : public GameState {
	private:
		Animation* loadingAnimation;

		std::thread loaderThread;
		std::promise<PlayingGameState*> loaderPromise;
		std::future<PlayingGameState*> loaderFuture;

	public:
		LoadingGameState(Renderer* renderer);

		void enter();

		bool loaderIsReady();

		void update();
		void draw();
};

