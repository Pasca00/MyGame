#pragma once

#include "../State/PlayerState/PlayerState.h"
#include "../State/PlayerState/IdlePlayerState.h"
#include "../State/PlayerState/WalkingPlayerState.h"
#include "../State/PlayerState/FallingPlayerState.h"
#include "../State/PlayerState/AttackPlayerState.h"
#include "../Physics/Movable.h"

class Level;

class Player : public Movable {
	private:
		int health;

		int textureW;
		int textureH;
		int sizeMultiplier;

		PlayerState* currentState_;

		class Healthbar {
		private:
			Player* player;

		public:
			Healthbar(Player* player);

			void setHealth(int health);

			View* container;
			View* health;
		} *healthbar;

	public:
		Player(int health, SDL_Rect dstrect, int8_t direction);

		void handleInput(Level* level, Input* input);
		void update();
		void draw();
		void drawHealthbar();

		void drawToRelativePosition(SDL_Rect cameraPos);

		SDL_Texture* getCurrentTexture();

		void setState(PlayerState* state);

		IdlePlayerState* idleState;
		WalkingPlayerState* walkingState;
		FallingPlayerState* fallingState;
		AttackPlayerState* attackState;
};

