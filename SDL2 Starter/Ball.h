
#ifndef Ball_h
#define Ball_h

#include <stdio.h>
#include "Game.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL2/SDL.h>

class Ball : public GameObject {

private:
    int r;
    int g;
    int b;

public:
    Ball(int X, int Y, int W, int H);
    virtual void draw();
    virtual void update();
    virtual void clean();

    void switchYVel();
    void switchXVel();
    void receiveImpulse(float x, float y);
    void setColor(int _r, int _g, int _b);
    void changeSpeed(float delta);

    bool isOutOfFieldLeft;
    bool isOutOfFieldRight;
};

#endif
