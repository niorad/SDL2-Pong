//
//  GameObject.h
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 05.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h
#pragma once

#include <SDL2/SDL.h>
#include "Vector2D.h"
#include <string>

using namespace std;

class GameObject {

public:
    GameObject(string TEX_ID, int X, int Y, int W, int H, float SCALE, int NUM_FRAMES);
    virtual void draw();
    virtual void update();
    virtual void clean();
    float getW() { return rect.w; }
    float getH() { return rect.h; }
    Vector2D& getPos() { return pos; }
    string getTextureID() { return textureID; }
    virtual bool checkCollision(Vector2D* vec);

protected:
    virtual ~GameObject() {}
    SDL_Rect rect;
    Vector2D pos, vel;
    float scale = 1;
    int curRow = 0, curFrame = 0, numFrames = 1;
    double rotate = 0.0;
    string textureID;
};




#endif /* GameObject_h */
