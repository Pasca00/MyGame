#pragma once

#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1

class Movable {
	protected:
		int velocity;
		int fallSpeed;
		int acceleration;
		int velocityCap;
		signed char direction;

	public:
		Movable(int velocity, int fallSpeed, int acceleration, int velocityCap, signed char direction);

		void setDirection(signed char direction);
		signed char getDirection();

		void setVelocity(int velocity);
		int getVelocity();

		void setAcceleration(int acceleration);
		int getAcceleration();

		void accelerate();
};

