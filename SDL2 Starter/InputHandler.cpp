//
//  InputHandler.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 03.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::instance = 0;

void InputHandler::init() {
}


void InputHandler::update() {
    
    keystates = SDL_GetKeyboardState(0);
    SDL_Event event;
    
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                _Game::Instance()->exit();
                break;
            case SDL_KEYDOWN:
                onKeyDown(&event);
                break;
            case SDL_KEYUP:
                onKeyUp(&event);
                break;
            default:
                break;
        }
    }
}



void InputHandler::onKeyDown(SDL_Event* event) {
    cout << "Key pressed: " << SDL_GetKeyName(event->key.keysym.sym) << endl;
    _Game::Instance()->getStateMachine()->onKeyDown(event);
}


void InputHandler::onKeyUp(SDL_Event* event) {
    cout << "Key Released: " << SDL_GetKeyName(event->key.keysym.sym) << endl;
    _Game::Instance()->getStateMachine()->onKeyUp(event);
}


bool InputHandler::isKeyDown(SDL_Scancode key) {

    if(keystates != 0) {
        if(keystates[key] == 1) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}


void InputHandler::clean() {
    
}





















