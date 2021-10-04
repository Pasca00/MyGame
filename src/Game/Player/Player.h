#pragma once

#include "../State/PlayerState/PlayerState.h"
#include "../State/PlayerState/IdlePlayerState.h"
#include "../State/PlayerState/WalkingPlayerState.h"
#include "../State/PlayerState/FallingPlayerState.h"
#include "../Physics/Movable.h"

class Player : public Movable {
	private:
		int health;
		//SDL_Rect posRect;
		//SDL_Rect renderRect;

		int textureW;
		int textureH;
		int sizeMultiplier;

		PlayerState* currentState_;

	public:
		Player(int health, SDL_Rect dstrect, int8_t direction);

		void handleInput(Input* input);
		void update();
		void draw();

		void drawToRelativePosition(SDL_Rect cameraPos);

		SDL_Texture* getCurrentTexture();

		void setState(PlayerState* state);

		IdlePlayerState* idleState;
		WalkingPlayerState* walkingState;
		FallingPlayerState* fallingState;
};

