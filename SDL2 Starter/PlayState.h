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
    void handleBallCollision(GameObject * paddle);
    void drawField();
    void updateResults();
    void setNewBall();
    Paddle* player;
    Paddle* enemy;
    Ball* ball;
    Results* results;
    SDL_Rect fieldMiddleLine;
    SDL_Rect fieldMiddlePoint;
    int scorePlayer;
    int scoreEnemy;
    Mix_Chunk* blip;

};


#endif
