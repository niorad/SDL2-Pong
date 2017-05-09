#ifndef PlayState_h
#define PlayState_h
#pragma once

#include <stdio.h>
#include "GameState.h"
#include "Paddle.h"
#include "Ball.h"
#include "Results.h"
#include <string>


class PlayState : public GameState {

public:
    void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual void onKeyDown(SDL_Event* e);
    virtual void onKeyUp(SDL_Event* e);
    virtual string getStateID() const { return playID; }

private:

    static const string playID;
    bool collisionIsSharp;
    void handleBallCollision();
    Paddle* paddle;
    Ball* ball;
    Results* results;

};


#endif
