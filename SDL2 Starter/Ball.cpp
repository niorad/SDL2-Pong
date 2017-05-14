
#include "Ball.h"
#include <iostream>

using namespace std;

Ball::Ball(int X, int Y, int W, int H): GameObject(X, Y, W, H) {
    cout << "The ball is here" << endl;
    r = 255;
    g = 255;
    b = 255;
    pos.setX(X);
    pos.setY(Y);
    rect.x = X;
    rect.y = Y;
    rect.w = W;
    rect.h = H;
    vel.setX(3);
    vel.setY(2);
    isOutOfFieldLeft = false;
    isOutOfFieldRight = false;
}


void Ball::update() {

    pos.setX(pos.getX() + vel.getX());
    pos.setY(pos.getY() + vel.getY());

    if(pos.getX() > _Game::Instance()->getGameWidth() - rect.w) {
        isOutOfFieldRight = true;
    }

    if(pos.getY() > _Game::Instance()->getGameHeight() - rect.h) {
        pos.setY(_Game::Instance()->getGameHeight() - rect.h - 1);
        vel.setY(-vel.getY());
    }

    if(pos.getX() < 0) {
        isOutOfFieldLeft = true;
    }

    if(pos.getY() < 0) {
        pos.setY(0);
        vel.setY(-vel.getY());
    }

    rect.x = pos.getX();
    rect.y = pos.getY();
}

void Ball::reset(int x, int y) {
    pos.setX(x);
    pos.setY(y);
    vel.setX(3);
    vel.setY(2);
    isOutOfFieldLeft = false;
    isOutOfFieldRight = false;
}

void Ball::setColor(int _r, int _g, int _b) {
    r = _r;
    g = _g;
    b = _b;
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

void Ball::changeSpeed(float delta) {
    vel = vel * delta;
}

void Ball::draw() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), r, g, b, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &rect);
}


void Ball::clean() {
    GameObject::clean();
}
