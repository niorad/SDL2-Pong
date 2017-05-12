#include "Paddle.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"
using namespace std;



Paddle::Paddle(int X, int Y, int W, int H): GameObject(X, Y, W, H) {

    cout << "Yay Paddle is here" << endl;

    pos.setX(X);
    pos.setY(Y);
    rect.x = X;
    rect.y = Y;
    rect.w = W;
    rect.h = H;
    isMovingUp = false;
    isMovingDown = false;
    currentSpeed = 0;
    speed = 300;
    acceleration = 40;
}

void Paddle::update() {

    if(isMovingDown) {
        currentSpeed += acceleration;
        if(currentSpeed > speed) {
            currentSpeed = speed;
        }
    } else if(isMovingUp) {
        currentSpeed -= acceleration;
        if(currentSpeed < -(speed)) {
            currentSpeed = -(speed);
        }
    } else {
        currentSpeed = 0;
    }

    pos.setY(pos.getY() + currentSpeed * _Game::Instance()->delta());

    if(pos.getY() < 0) {
        pos.setY(0);
    }

    if(pos.getY() > _Game::Instance()->getGameHeight() - rect.h) {
        pos.setY(_Game::Instance()->getGameHeight() - rect.h);
    }

    rect.x = pos.getX();
    rect.y = pos.getY();
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

void Paddle::setCenterY(float y) {
    pos.setY(y - (rect.h/2));
}

void Paddle::draw() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 255, 240, 242, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &rect);
}

void Paddle::clean() {
    GameObject::clean();
}
