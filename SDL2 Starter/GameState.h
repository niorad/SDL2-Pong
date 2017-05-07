//
//  GameState.hpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 04.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef GameState_h
#define GameState_h
#pragma once

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include "GameObject.h"
#include <map>

using namespace std;

class GameState {

public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;
    virtual void onKeyDown(SDL_Event* e) = 0;
    virtual void onKeyUp(SDL_Event* e) = 0;
    virtual void onMouseButtonUp(SDL_Event& e) = 0;
    virtual void onMouseButtonDown(SDL_Event& e) = 0;
    virtual void onMouseMove(SDL_Event& e) = 0;
    virtual string getStateID() const = 0;
    GameObject* getObjectByID(string id) { return gameObjects[id]; }

protected:

    map<string, GameObject*> gameObjects;
};

typedef map<string, GameObject*>::iterator it_type;



#endif /* GameState_hpp */
