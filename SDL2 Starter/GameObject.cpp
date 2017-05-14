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

void GameObject::placeAfter(GameObject* gameObject) {
    pos.setX(gameObject->getPos().getX() + gameObject->getW() + 1);
}

void GameObject::placeBefore(GameObject* gameObject) {
    pos.setX(gameObject->getPos().getX() - getW() - 1);
}

void GameObject::placeAbove(GameObject* gameObject) {
    pos.setY(gameObject->getPos().getY() - getH() - 1);
}

void GameObject::placeBelow(GameObject* gameObject) {
    pos.setY(gameObject->getPos().getY() + gameObject->getW() + 1);
}


collisionDirection GameObject::checkCollisionDirection(GameObject* gameObject) {

    // https://gamedev.stackexchange.com/questions/29786/a-simple-2d-rectangle-collision-algorithm-that-also-determines-which-sides-that

    float w = 0.5 * (getW() + gameObject->getW());
    float h = 0.5 * (getH() + gameObject->getH());
    float dx = (pos.getX() + (getW() / 2)) - (gameObject->getPos().getX() + (gameObject->getW() / 2));
    float dy = (pos.getY() + (getH() / 2)) - (gameObject->getPos().getY() + (gameObject->getH() / 2));

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

float GameObject::getCenterX() {
    return pos.getX() + (rect.w / 2);
}

float GameObject::getCenterY() {
    return pos.getY() + (rect.h / 2);
}


void GameObject::clean() {    
}
