//
//  InputHandler.hpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 03.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef InputHandler_hpp
#define InputHandler_hpp
#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};


class InputHandler {

public:
    
    static InputHandler* Instance() {
        if(instance == 0) {
            instance = new InputHandler();
        }
        
        return instance;
    }
    
    void init();
    void update();
    void clean();
    
    // Keyboard
    
    bool isKeyDown(SDL_Scancode key);
    
    // Mouse
    
    bool getMouseButtonState(int buttonNum) {
        return mouseButtonStates[buttonNum];
    }
    
    Vector2D* getMousePos() {
        return mPos;
    }
    
    void reset();
    
private:
    
    InputHandler() {}
    ~InputHandler() {}
    
    static InputHandler* instance;
    
    // Keyboard
    
    const Uint8* keystates;
    
    void onKeyDown(SDL_Event* event);
    void onKeyUp(SDL_Event* event);
    
    // Mouse
    
    std::vector<bool> mouseButtonStates;
    Vector2D* mPos;
    
    void onMouseMove(SDL_Event& e);
    void onMouseButtonDown(SDL_Event& e);
    void onMouseButtonUp(SDL_Event& e);
    
};

typedef InputHandler _InputHandler;

#endif /* InputHandler_hpp */
