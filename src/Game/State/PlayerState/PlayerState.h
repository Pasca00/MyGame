#pragma once

#include "../../Input/InputCollector.h"
#include "../../Player/Player.h"

class PlayerState {
	public:
		virtual void handleInput(Input* input) = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
};

