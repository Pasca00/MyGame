#include "../Game.h"
#include "PlayingGameState.h"
#include "../Physics/PhysicsEngine.h"

PlayingGameState::PlayingGameState() : GameState() {
	this->level = new Level(Window::BASE_WINDOW_HEIGHT / 96, 80);
}

void PlayingGameState::enter() { }

void PlayingGameState::handleInput(Game* game, Input* input) {
	if (input->KEY_ESCAPE || input->QUIT) {
		game->setRunning(false);
	}

	level->handleInput(input);
}

void PlayingGameState::update() {
	level->update();
}

void PlayingGameState::draw() {
	level->draw();
}