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


bool PlayState::onEnter() {
    cout << "Entering PlayState" << endl;
    paddle = new Paddle(50, 180, 15, 80);
    ball = new Ball(100, 300, 10, 10);
    results = new Results();
    collisionIsSharp = true;
    return true;
}


void PlayState::update() {

    paddle->update();
    ball->update();
}


void PlayState::render() {

    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 133, 135, 128, 255);
    SDL_RenderClear(_Game::Instance()->getRenderer());

    collisionDirection ballTouchingPaddle = ball->checkCollisionDirection(paddle);

    if(!collisionIsSharp && ballTouchingPaddle == NONE) {
        collisionIsSharp = true;
    }

    if(collisionIsSharp) {

        switch(ballTouchingPaddle) {
            case NONE:
                break;
            case TOP:
            case BOTTOM:
                ball->switchYVel();
                collisionIsSharp = false;
                break;
            case LEFT:
            case RIGHT:
                ball->switchXVel();
                collisionIsSharp = false;
                handleBallCollision();
                break;
        }
    }
    paddle->draw();
    ball->draw();
    results->draw();
}


void PlayState::handleBallCollision() {
    int dir = ball->getVel().getX() > 0 ? -1 : 1;
    float rotationAmount = ((paddle->getCenterY() - ball->getCenterY()) / 40) * dir;
    float currentXVel = sqrt(ball->getVel().getX() * ball->getVel().getX() + ball->getVel().getY() * ball->getVel().getY());
    float newXVel = currentXVel * cos(rotationAmount);
    float newYVel = currentXVel * sin(rotationAmount);
    ball->receiveImpulse(*new Vector2D(newXVel, newYVel));
}


bool PlayState::onExit() {

    paddle->clean();
    ball->clean();
    results->clean();

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

