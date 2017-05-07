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
    for(int i = 0; i < 3; i++) {
        mouseButtonStates.push_back(false);
    }
    mPos = new Vector2D(0, 0);
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
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
            default:
                break;
        }
    }
}



void InputHandler::onMouseButtonDown(SDL_Event& e) {
    if(e.button.button == SDL_BUTTON_LEFT) {
        mouseButtonStates[LEFT] = true;
        cout << "Left Mouse Button Pressed" << endl;
    } else if(e.button.button == SDL_BUTTON_MIDDLE) {
        mouseButtonStates[MIDDLE] = true;
        cout << "Middle Mouse Button Pressed" << endl;
    } else if(e.button.button == SDL_BUTTON_RIGHT) {
        mouseButtonStates[RIGHT] = true;
        cout << "Right Mouse Button Pressed" << endl;
    }
    _Game::Instance()->getStateMachine()->onMouseButtonDown(e);

}

void InputHandler::onMouseButtonUp(SDL_Event& e) {
    if(e.button.button == SDL_BUTTON_LEFT) {
        mouseButtonStates[LEFT] = false;
        cout << "Left Mouse Button Released" << endl;
    } else if(e.button.button == SDL_BUTTON_MIDDLE) {
        mouseButtonStates[MIDDLE] = false;
        cout << "Middle Mouse Button Released" << endl;
    } else if(e.button.button == SDL_BUTTON_RIGHT) {
        mouseButtonStates[RIGHT] = false;
        cout << "Right Mouse Button Released" << endl;
    }
    _Game::Instance()->getStateMachine()->onMouseButtonUp(e);
}


void InputHandler::onMouseMove(SDL_Event& e) {
    mPos->setX(e.motion.x);
    mPos->setY(e.motion.y);
    cout << "MouseX: " << mPos->getX() << ", MouseY: " << mPos->getY() << endl;
    _Game::Instance()->getStateMachine()->onMouseMove(e);
}


void InputHandler::reset() {
    for(int i = 0; i< mouseButtonStates.size(); i++) {
        mouseButtonStates[i] = false;
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





















