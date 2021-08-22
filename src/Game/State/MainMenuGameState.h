#pragma once
#include "GameState.h"
#include "../Visuals/View.h"
#include "../Render/Renderer.h"

class MainMenuGameState : public GameState {
	private:
		View* wallpaperView;


	public:
		MainMenuGameState(Renderer* renderer);

		void handleInput(Game* game, Input *input) override;
		void draw();

};