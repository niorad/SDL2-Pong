#ifndef GameObject_h
#define GameObject_h
#pragma once

#include <SDL2/SDL.h>
#include "Vector2D.h"
#include <string>

using namespace std;

enum collisionDirection {NONE, TOP, RIGHT, BOTTOM, LEFT};

class GameObject {

public:
    GameObject(int X, int Y, int W, int H);
    virtual void draw();
    virtual void update();
    virtual void clean();
    float getW() { return rect.w; }
    float getH() { return rect.h; }
    float getCenterX();
    float getCenterY();
    SDL_Rect* getRect() { return &rect; }
    Vector2D& getPos() { return pos; }
    Vector2D& getVel() { return vel; }
    virtual bool checkCollision(Vector2D* vec);
    virtual bool checkOverlap(GameObject* gameObject);
    virtual collisionDirection checkCollisionDirection(GameObject* gameObject);

protected:
    virtual ~GameObject() {}
    SDL_Rect rect;
    Vector2D pos, vel;
    double rotate = 0.0;
};

#endif
