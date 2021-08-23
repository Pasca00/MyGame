#pragma once
#include "GameState.h"
#include "../Visuals/View.h"
#include "../Visuals/ButtonView.h"
#include "../Render/Renderer.h"

class MainMenuGameState : public GameState {
	private:
		View* wallpaperView;
		ButtonView* playButtonView;


	public:
		MainMenuGameState(Renderer* renderer);

		void handleInput(Game* game, Input *input) override;
		void draw();

};