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

#define PADDLE_SPEED 10


Paddle::Paddle(string TEX_ID, int X, int Y, int W, int H, int SCALE): GameObject(TEX_ID, X, Y, W, H, SCALE, 3) {
    cout << "Yay Paddle is here" << endl;
    body.x = X;
    body.y = Y;
    body.w = W;
    body.h = H;
}

void Paddle::update() {

}

void Paddle::moveUp() {
    body.y -= PADDLE_SPEED;
}

void Paddle::moveDown() {
    body.y += PADDLE_SPEED;
}

void Paddle::draw() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 255, 240, 242, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &body);
    
}

void Paddle::clean() {
    GameObject::clean();
}
