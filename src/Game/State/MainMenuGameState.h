#pragma once

#include "GameState.h"
#include "LoadingGameState.h"
#include "PlayingGameState.h"

#include "../Visuals/Core/Shader.h"
#include "../Visuals/View.h"
#include "../Visuals/ButtonView.h"
#include "../Render/Renderer.h"

class MainMenuGameState : public GameState {
	private:
		View* wallpaperView;
		ButtonView* playButtonView;

		Shader* buttonShader;

	public:
		MainMenuGameState();

		void handleInput(Game* game, Input *input) override;
		void update() override;
		void draw() override;
};