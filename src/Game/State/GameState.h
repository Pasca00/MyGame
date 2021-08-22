#pragma once
#include "State.h"

class GameState : public State {
    private:

    public:
        GameState() : State() {}

        virtual void handleInput(Game* game, Input* input);
        virtual void update() {}
        virtual void draw() {}
};

