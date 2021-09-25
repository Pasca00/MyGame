#pragma once

#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1

class Movable {
	protected:
		int xVelocity;
		int yVelocity;
		int acceleration;
		int velocityCap;
		signed char xDirection;
		signed char yDirection;

		bool collisionLeft;
		bool collisionRight;
		bool collisionDown;
		bool collisionUp;

	public:
		Movable(int velocity, int fallSpeed, int acceleration, int velocityCap, signed char direction);

		void setDirection(signed char direction);
		signed char getDirection();

		void setVelocity(int velocity);
		int getVelocity();

		void setAcceleration(int acceleration);
		int getAcceleration();

		void setLeftCollision(bool v);
		void setRightCollision(bool v);
		void setDownCollision(bool v);
		void setUpCollision(bool v);

		bool collidesLeft();
		bool collidesRight();
		bool collidesDown();
		bool collidesUp();

		void accelerate();
};

