#pragma once
#include <SDL.h>

typedef struct Input {
	bool KEY_W;
	bool KEY_A;
	bool KEY_S;
	bool KEY_D;
	bool KEY_E;
	bool KEY_SPACE;
	bool KEY_ESCAPE;
	
	bool LEFT_MOUSE_CLICK;
	bool RIGHT_MOUSE_CLICK;

	int MOUSE_X;
	int MOUSE_Y;

	bool QUIT;
} Input;

class InputCollector {
	private:
		Input input;
		void flushInputs();
	public:
		InputCollector();
		Input getInput();
		void collectInput();

		static void flushInput(Input* input);
};

