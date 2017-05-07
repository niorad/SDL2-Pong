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
#include "TextureManager.h"

GameObject::GameObject(string TEX_ID, int X, int Y, int W, int H, float SCALE, int NUM_FRAMES) : pos(X,Y), vel(0,0) {

    rect = {X, Y, W, H};
    scale = SCALE;
    textureID = TEX_ID;
    numFrames = NUM_FRAMES;

}

void GameObject::update() {
    pos += vel;
    rect.x = pos.getX();
    rect.y = pos.getY();
}

void GameObject::draw() {
    _TextureManager::Instance()->drawFrame(textureID, rect.x, rect.y, rect.w, rect.h, scale, curRow, curFrame, rotate, _Game::Instance()->getRenderer());
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

void GameObject::clean() {}
