
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
    vel.setX(3);
    vel.setY(2);
}


void Ball::update() {

    pos.setX(pos.getX() + vel.getX());
    pos.setY(pos.getY() + vel.getY());

    if(pos.getX() > 620) {
        pos.setX(619);
        vel.setX(-vel.getX());
    }

    if(pos.getY() > 460) {
        pos.setY(459);
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
    pos += vel;
}

void Ball::switchXVel() {
    vel.setX(-vel.getX());
    pos += vel;
}

void Ball::draw() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 30, 30, 35, 255);
    SDL_RenderFillRect(_Game::Instance()->getRenderer(), &rect);
}


void Ball::clean() {
    GameObject::clean();
}
