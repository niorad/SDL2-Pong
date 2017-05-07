//
//  GameStateMachine.h
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 04.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef GameStateMachine_h
#define GameStateMachine_h

#pragma once

#include "GameState.h"
#include <vector>
#include <SDL2/SDL.h>

class GameStateMachine {

public:

    GameStateMachine() {}
    ~GameStateMachine() {}

    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();


    void update();
    void render();
    void onKeyDown(SDL_Event* e);
    void onKeyUp(SDL_Event* e);
    void onMouseButtonUp(SDL_Event& e);
    void onMouseButtonDown(SDL_Event& e);
    void onMouseMove(SDL_Event& e);


    
private:
    vector<GameState*> gameStates;

};

#endif /* GameStateMachine_h */
