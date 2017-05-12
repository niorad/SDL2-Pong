
#ifndef Game_h
#define Game_h
#pragma once

#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <string>
#include "InputHandler.h"
#include "GameStateMachine.h"

using namespace std;


class Game {


public:

    static Game* Instance() {
        if(instance == 0) {
            instance = new Game();
        }
        return instance;
    }

    
    bool init(const char* title, int x, int y, int width, int height, int flags);
    
    void update();
    void handleEvents();
    void render();
    void clean();
    void exit();


    bool isRunning() {
        return running;
    }
    
    SDL_Renderer* getRenderer() const {
        return renderer;
    }

    SDL_Window* getWindow() const {
        return window;
    }

    GameStateMachine* getStateMachine() { return gameStateMachine; }

    float delta() { return dT; }
    int getGameWidth() { return gameWidth; }
    int getGameHeight() { return gameHeight; }


private:
    
    static Game* instance;

    Game() {};
    ~Game() {};

    SDL_Window* window;
    SDL_Renderer* renderer;

    GameStateMachine* gameStateMachine;
    
    bool running;
    float dT;
    Uint32 lastUpdate;
    int gameWidth;
    int gameHeight;

};

typedef Game _Game;

#endif
