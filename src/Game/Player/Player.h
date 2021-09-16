#pragma once

#include "../State/PlayerState/PlayerState.h"
#include "../State/PlayerState/IdlePlayerState.h"
#include "../State/PlayerState/WalkingPlayerState.h"
#include "../Physics/Movable.h"

class Player : public Movable {
	private:
		int health;
		SDL_Rect posRect;
		SDL_Rect renderRect;

		PlayerState* currentState_;

	public:
		Player(int health, SDL_Rect posRect, int8_t direction);

		void handleInput(Input* input);
		void update();
		void draw();

		SDL_Texture* getCurrentTexture();
		SDL_Rect getRect();
		SDL_Rect buildRenderRect();

		void setRect(SDL_Rect posRect);

		void setState(PlayerState* state);

		IdlePlayerState* idleState;
		WalkingPlayerState* walkingState;
};

