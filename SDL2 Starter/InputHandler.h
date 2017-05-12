#ifndef InputHandler_hpp
#define InputHandler_hpp
#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"


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
    
    
private:
    
    InputHandler() {}
    ~InputHandler() {}
    
    static InputHandler* instance;
    
    // Keyboard
    
    const Uint8* keystates;
    
    void onKeyDown(SDL_Event* event);
    void onKeyUp(SDL_Event* event);
        
};

typedef InputHandler _InputHandler;

#endif 
