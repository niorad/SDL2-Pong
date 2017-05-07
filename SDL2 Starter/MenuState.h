//
//  MenuState.hpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 05.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef MenuState_hpp
#define MenuState_hpp

#include "GameState.h"
#include "TextureManager.h"
#include <string>

class MenuState : public GameState {

public:

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual void onKeyDown(SDL_Event* e);
    virtual void onKeyUp(SDL_Event* e);
    virtual void onMouseButtonUp(SDL_Event& e);
    virtual void onMouseButtonDown(SDL_Event& e);
    virtual void onMouseMove(SDL_Event& e);

    virtual string getStateID() const { return menuID; }

    
private:
    static const string menuID;

};



#endif /* MenuState_h */
