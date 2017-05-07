//
//  PlayState.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 06.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "GameStateMachine.h"
#include "TextureManager.h"
#include "Button.h"

const string PlayState::playID = "PLAY";

void PlayState::update() {

    for(it_type iterator = gameObjects.begin(); iterator != gameObjects.end(); iterator++) {
        iterator->second->update();
    }

}

void PlayState::render() {

    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 0, 255, 255, 255);

    for(it_type iterator = gameObjects.begin(); iterator != gameObjects.end(); iterator++) {
        iterator->second->draw();
    }
    
}


bool PlayState::onEnter() {
    cout << "Entering PlayState" << endl;
    return true;
}


bool PlayState::onExit() {

    for(it_type iterator = gameObjects.begin(); iterator != gameObjects.end(); iterator++) {
        iterator->second->clean();
    }

    gameObjects.clear();

    cout << "Exiting PlayState" << endl;
    return false;
}

void PlayState::onKeyDown(SDL_Event* e) {

}

void PlayState::onKeyUp(SDL_Event* e) {

}

void PlayState::onMouseButtonDown(SDL_Event& e) {

}

void PlayState::onMouseButtonUp(SDL_Event& e) {

}

void PlayState::onMouseMove(SDL_Event& e) {
    
}
