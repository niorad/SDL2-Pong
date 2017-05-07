//
//  Paddle.cpp
//  SDL2 Pong
//
//  Created by Antonio Radovcic on 07.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "Paddle.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"
using namespace std;

#define PADDLE_SPEED 250


Paddle::Paddle(string TEX_ID, int X, int Y, int W, int H, int SCALE): GameObject(TEX_ID, X, Y, W, H, SCALE, 3) {
    cout << "Yay Paddle is here" << endl;
    body.x = X;
    body.y = Y;
    body.w = W;
    body.h = H;
    isMovingUp = false;
    isMovingDown = false;
}

void Paddle::update() {

    if(isMovingUp) {
        body.y -= PADDLE_SPEED * _Game::Instance()->delta();
    }

    if(isMovingDown) {
        body.y += PADDLE_SPEED * _Game::Instance()->delta();
    }

    if(body.y < 0) {
        body.y = 0;
    }

    if(body.y > 400) {
        body.y = 400;
    }


}

void Paddle::startMovingUp() {
    isMovingUp = true;
}

void Paddle::startMovingDown() {
    isMovingDown = true;
}

void Paddle::stopMovingUp() {
    isMovingUp = false;
}

void Paddle::stopMovingDown() {
    isMovingDown = false;
}

void Paddle::draw() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 255, 240, 242, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &body);
    
}

void Paddle::clean() {
    GameObject::clean();
}
