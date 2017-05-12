
#ifndef Results_hpp
#define Results_hpp

#include <stdio.h>
#include "Game.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL2/SDL.h>

class Results : public GameObject {

public:
    Results();
    virtual void draw();
    virtual void update();
    virtual void clean();
    void updateText(string newText);

private:
    TTF_Font* uni;
    SDL_Rect srcRect;
    SDL_Texture* textTexture;
};

#endif


