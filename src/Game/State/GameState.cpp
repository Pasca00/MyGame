#include "GameState.h"
#include "../Game.h"

void GameState::enter() { }

void GameState::handleInput(Game* game, Input* input) {
	if (input->QUIT) {
		game->setRunning(false);
	}
}