//
//  Button.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 06.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "Button.h"
#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"

Button::Button(string TEX_ID, int X, int Y, int W, int H, int SCALE) : GameObject(TEX_ID, X, Y, W, H, SCALE, 3) {
    curFrame = MOUSE_OUT;
    _TextureManager::Instance()->load("assets/hello.png", "hello", _Game::Instance()->getRenderer());
    _TextureManager::Instance()->load("assets/trouble.png", "trouble", _Game::Instance()->getRenderer());

}


void Button::update() {
    if(checkCollision(_InputHandler::Instance()->getMousePos())) {
        if(_InputHandler::Instance()->getMouseButtonState(LEFT)) {
            curFrame = MOUSE_DOWN;
            released = false;
        } else {
            released = true;
            curFrame = MOUSE_OVER;
        }
    } else {
        curFrame = MOUSE_OUT;
    }
}

void Button::draw() {
    GameObject::draw();
}

void Button::clean() {
    GameObject::clean();
}
