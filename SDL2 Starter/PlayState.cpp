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
#include "Paddle.h"

const string PlayState::playID = "PLAY";

void PlayState::update() {

    for(it_type iterator = gameObjects.begin(); iterator != gameObjects.end(); iterator++) {
        iterator->second->update();
    }

    paddle->update();
}

void PlayState::render() {

    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 133, 135, 128, 255);
    SDL_RenderClear(_Game::Instance()->getRenderer());

    for(it_type iterator = gameObjects.begin(); iterator != gameObjects.end(); iterator++) {
        iterator->second->draw();
    }

    paddle->draw();

}


bool PlayState::onEnter() {

    cout << "Entering PlayState" << endl;

    paddle = new Paddle("paddle", 20, 180, 15, 80, 1);

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
    const int current_key = e->key.keysym.scancode;
    if(current_key == 81) {
        paddle->startMovingDown();
    } else if(current_key == 82) {
        paddle->startMovingUp();
    }
}

void PlayState::onKeyUp(SDL_Event* e) {
    const int current_key = e->key.keysym.scancode;
    if(current_key == 81) {
        paddle->stopMovingDown();
    } else if(current_key == 82) {
        paddle->stopMovingUp();
    }
}

