#pragma once

#include <thread>
#include <future>

#include "State.h"

class GameState : public State {
    private:

    public:
        GameState() : State() {}

        virtual void enter();
        virtual void handleInput(Game* game, Input* input);
        virtual void update() = 0;
        virtual void draw() = 0;
};

