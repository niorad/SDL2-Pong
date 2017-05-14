#ifndef PlayState_h
#define PlayState_h
#pragma once

#include <stdio.h>
#include "GameState.h"
#include "Paddle.h"
#include "Ball.h"
#include "Results.h"
#include "Item.h"
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
    void resetBall();
    Paddle* player;
    Paddle* enemy;
    Ball* ball;
    Results* results;
    const int ITEM_COUNT = 5;
    Item* items [5];
    SDL_Rect fieldMiddleLine;
    SDL_Rect fieldMiddlePoint;
    int scorePlayer;
    int scoreEnemy;
    int totalCollisions;

    Mix_Chunk* blip;
    Mix_Chunk* wall;
    Mix_Chunk* pickup;
    Mix_Chunk* point;

};


#endif
