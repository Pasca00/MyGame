#pragma once

#include <SDL.h>
#include "Hitbox.h"
#include "../glm/glm.hpp"

#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1
#define DIRECTION_UP    1
#define DIRECTION_DOWN -1

class Movable {
	protected:
		float xVelocity;
		float yVelocity;
		float jumpSpeed;
		float acceleration;
		float velocityCap;
		signed char xDirection;
		signed char yDirection;

		Hitbox* hitbox;

		bool accelerating;

		bool collisionLeft;
		bool collisionRight;
		bool collisionDown;
		bool collisionUp;

	public:
		Movable(float velocity, float jumpSpeed, float fallSpeed, float acceleration, float velocityCap, signed char direction, signed char yDirection);

		void setXDirection(signed char xDirection);
		signed char getXDirection();

		void setYDirection(signed char yDirection);
		signed char getYDirection();

		void setXVelocity(int xVelocity);
		int getXVelocity();

		void setYVelocity(int yVelocity);
		int getYVelocity();

		void setXVelocityCap(int xVelocityCap);
		int getXVelocityCap();

		void setHitbox(Hitbox* hitbox);
		Hitbox* getHitbox();

		void setAcceleration(int acceleration);
		int getAcceleration();

		void setLeftCollision(bool v);
		void setRightCollision(bool v);
		void setDownCollision(bool v);
		void setUpCollision(bool v);

		void startAccelerating();
		void stopAccelerating();
		bool isAccelerating();

		bool collidesLeft();
		bool collidesRight();
		bool collidesDown();
		bool collidesUp();

		void accelerate();
		void jump();
};

