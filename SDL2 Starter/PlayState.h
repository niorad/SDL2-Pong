//
//  PlayState.hpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 06.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef PlayState_hpp
#define PlayState_hpp
#pragma once

#include <stdio.h>
#include "GameState.h"
#include <string>


class PlayState : public GameState {

public:
    void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual void onKeyDown(SDL_Event* e);
    virtual void onKeyUp(SDL_Event* e);
    virtual void onMouseButtonUp(SDL_Event& e);
    virtual void onMouseButtonDown(SDL_Event& e);
    virtual void onMouseMove(SDL_Event& e);
    virtual string getStateID() const { return playID; }

private:

    static const string playID;

};


#endif /* PlayState_hpp */
