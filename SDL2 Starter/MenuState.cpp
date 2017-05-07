//
//  MenuState.cpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 05.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#include "MenuState.h"
#include "PlayState.h"
#include <iostream>
#include "Game.h"
#include "GameStateMachine.h"
#include "Button.h"

const string MenuState::menuID = "MENU";



void MenuState::update() {
    for(it_type iterator = gameObjects.begin(); iterator != gameObjects.end(); iterator++) {
        iterator->second->update();
    }

}

void MenuState::render() {
    SDL_SetRenderDrawColor(_Game::Instance()->getRenderer(), 0, 0, 0, 255);

    for(it_type iterator = gameObjects.begin(); iterator != gameObjects.end(); iterator++) {
        iterator->second->draw();
    }
}

bool MenuState::onEnter() {
    cout << "Entering MenuState" << endl;

    _TextureManager::Instance()->load("assets/hello.png", "hellobut", _Game::Instance()->getRenderer());
    _TextureManager::Instance()->load("assets/trouble.png", "troublebut", _Game::Instance()->getRenderer());

    gameObjects.insert(pair<string, GameObject*> ("hellobutton", new Button("hellobut", 100, 100, 90, 30, 1)));

    gameObjects.insert(pair<string, GameObject*> ("troublebutton", new Button("troublebut", 100, 180, 90, 30, 1)));

    return true;
}


bool MenuState::onExit() {

    for(it_type iterator = gameObjects.begin(); iterator != gameObjects.end(); iterator++) {
        iterator->second->clean();
    }

    gameObjects.clear();

    cout << "Exiting MenuState" << endl;
    return false;
}

void MenuState::onKeyDown(SDL_Event* e) {

}

void MenuState::onKeyUp(SDL_Event* e) {

}

void MenuState::onMouseButtonDown(SDL_Event& e) {

}

void MenuState::onMouseButtonUp(SDL_Event& e) {
    if(gameObjects["hellobutton"]->checkCollision(_InputHandler::Instance()->getMousePos())) {
        _Game::Instance()->getStateMachine()->changeState(new PlayState());
    }
    if(gameObjects["troublebutton"]->checkCollision(_InputHandler::Instance()->getMousePos())) {
        _Game::Instance()->getStateMachine()->changeState(new PlayState());
    }
}

void MenuState::onMouseMove(SDL_Event& e) {

}

