#pragma once

#include "../State/PlayerState/PlayerState.h"
#include "../State/PlayerState/IdlePlayerState.h"
#include "../State/PlayerState/WalkingPlayerState.h"

#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1

class Player {
	private:
		int health;
		SDL_Rect posRect;
		SDL_Rect renderRect;

		int8_t direction;
		PlayerState* currentState_;

		int velocity;
		int fallSpeed;
		int acceleration;
		int velocityCap;
		int accCap;

	public:
		Player(int health, SDL_Rect posRect, int8_t direction);

		void handleInput(Input* input);
		void update();
		void draw();

		SDL_Texture* getCurrentTexture();
		SDL_Rect getRect();
		SDL_Rect buildRenderRect();

		void setRect(SDL_Rect posRect);

		void setDirection(int8_t direction);
		int8_t getDirection();

		void setState(PlayerState* state);

		void accelerate();

		void setVelocity(int velocity);
		int getVelocity();

		void setAcceleration(int acceleration);
		int getAcceleration();

		IdlePlayerState* idleState;
		WalkingPlayerState* walkingState;
};

