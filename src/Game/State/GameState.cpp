#include "GameState.h"
#include "../Game.h"

void GameState::handleInput(Game* game, Input* input) {
	if (input->QUIT) {
		game->setRunning(false);
	}
}