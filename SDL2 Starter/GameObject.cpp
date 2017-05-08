//
//  GameObject.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 05.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include <stdio.h>
#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(int X, int Y, int W, int H) : pos(X,Y), vel(0,0) {
    rect = {X, Y, W, H};
}

void GameObject::update() {
    pos += vel;
    rect.x = pos.getX();
    rect.y = pos.getY();
}

void GameObject::draw() {
}


bool GameObject::checkCollision(Vector2D* vec) {
    if(vec->getX() > pos.getX()
       && vec->getX() < pos.getX() + getW()
       && vec->getY() > pos.getY()
       && vec->getY() < pos.getY() + getH()) {
        return true;
    }
    return false;
}


bool GameObject::checkOverlap(GameObject* gameObject) {

    int aLeft = pos.getX();
    int aRight = pos.getX() + rect.w;
    int aTop = pos.getY();
    int aBottom = pos.getY() + rect.h;

    int bLeft = gameObject->pos.getX();
    int bRight = gameObject->pos.getX() + gameObject->getW();
    int bTop = gameObject->pos.getY();
    int bBottom = gameObject->pos.getY() + gameObject->getH();

    return (aLeft < bRight && aRight > bLeft && aTop < bBottom && aBottom > bTop);
}



collisionDirection GameObject::checkCollisionDirection(GameObject* gameObject) {

    float w = 0.5 * (getW() + gameObject->getW());
    float h = 0.5 * (getH() + gameObject->getH());
    float dx = (pos.getX() + getW() / 2) - (gameObject->getPos().getX() + gameObject->getW() / 2);
    float dy = (pos.getY() + getH() / 2) - (gameObject->getPos().getY() + gameObject->getH() / 2);

    if(fabs(dx) <= w && fabs(dy) <= h) {

        float wy = w * dy;
        float hx = h * dx;

        if(wy > hx) {
            if(wy > (-hx)) {
                return TOP;
            } else {
                return LEFT;
            }
        } else {
            if(wy > (-hx)) {
                return RIGHT;
            } else {
                return BOTTOM;
            }
        }
    } else {
        return NONE;
    }

}



void GameObject::clean() {}
