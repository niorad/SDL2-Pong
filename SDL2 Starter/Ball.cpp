
#include "Ball.h"
#include <iostream>

using namespace std;

Ball::Ball(int X, int Y, int W, int H): GameObject(X, Y, W, H) {
    cout << "The ball is here" << endl;
    pos.setX(X);
    pos.setY(Y);
    rect.x = X;
    rect.y = Y;
    rect.w = W;
    rect.h = H;
    vel.setX(8);
    vel.setY(3);
}


void Ball::update() {

    pos.setX(pos.getX() + vel.getX());
    pos.setY(pos.getY() + vel.getY());

    if(pos.getX() > _Game::Instance()->getGameWidth() - rect.w) {
        pos.setX(_Game::Instance()->getGameWidth() - rect.w - 1);
        vel.setX(-vel.getX());
    }

    if(pos.getY() > _Game::Instance()->getGameHeight() - rect.h) {
        pos.setY(_Game::Instance()->getGameHeight() - rect.h - 1);
        vel.setY(-vel.getY());
    }

    if(pos.getX() < 0) {
        pos.setX(0);
        vel.setX(-vel.getX());
    }

    if(pos.getY() < 0) {
        pos.setY(0);
        vel.setY(-vel.getY());
    }

    rect.x = pos.getX();
    rect.y = pos.getY();
}

void Ball::switchYVel() {
    vel.setY(-vel.getY());
}

void Ball::switchXVel() {
    vel.setX(-vel.getX());
}

void Ball::receiveImpulse(float x, float y) {
    vel.setX(x);
    vel.setY(y);
}

void Ball::draw() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &rect);
}


void Ball::clean() {
    GameObject::clean();
}
