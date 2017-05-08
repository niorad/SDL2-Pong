//
//  PlayState.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 06.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "GameStateMachine.h"


const string PlayState::playID = "PLAY";

void PlayState::update() {

    paddle->update();
    ball->update();
}


void PlayState::render() {

    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 133, 135, 128, 255);
    SDL_RenderClear(_Game::Instance()->getRenderer());

    collisionDirection ballTouchingPaddle = ball->checkCollisionDirection(paddle);

    switch(ballTouchingPaddle) {
        case NONE:
            break;
        case TOP:
        case BOTTOM:
            ball->switchYVel();
            break;
        case LEFT:
        case RIGHT:
            ball->switchXVel();
            break;
    }


    paddle->draw();
    ball->draw();

}


bool PlayState::onEnter() {

    cout << "Entering PlayState" << endl;

    paddle = new Paddle(220, 180, 15, 80);
    ball = new Ball(100, 100, 20, 20);

    return true;
}


bool PlayState::onExit() {

    paddle->clean();
    ball->clean();

    cout << "Exiting PlayState" << endl;
    return false;
}

void PlayState::onKeyDown(SDL_Event* e) {
    const int current_key = e->key.keysym.scancode;
    if(current_key == 81) {
        paddle->startMovingDown();
    } else if(current_key == 82) {
        paddle->startMovingUp();
    }
}

void PlayState::onKeyUp(SDL_Event* e) {
    const int current_key = e->key.keysym.scancode;
    if(current_key == 81) {
        paddle->stopMovingDown();
    } else if(current_key == 82) {
        paddle->stopMovingUp();
    }
}

