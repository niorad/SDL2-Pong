
#ifndef Ball_h
#define Ball_h

#include <stdio.h>
#include "Game.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL2/SDL.h>

class Ball : public GameObject {

public:
    Ball(int X, int Y, int W, int H);
    virtual void draw();
    virtual void update();
    virtual void clean();

    void switchYVel();
    void switchXVel();
};

#endif
