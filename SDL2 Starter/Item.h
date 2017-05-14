
#ifndef Item_h
#define Item_h

#include <stdio.h>
#include "Game.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL2/SDL.h>

enum kindOfItem {
    accelerate, decellerate, growBall, shrinkBall, growPaddle, shrinkPaddle
};

class Item : public GameObject {

public:
    Item(int x, int y, kindOfItem kind);

    virtual void update();
    virtual void draw();
    virtual void clean();

};



#endif
