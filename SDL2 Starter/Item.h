
#ifndef Item_h
#define Item_h

#include <stdio.h>
#include "Game.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL2/SDL.h>

enum kindOfItem {
    accelerate, decelerate, growBall, shrinkBall, growPaddle, shrinkPaddle
};

class Item : public GameObject {

private:
    bool active;
    kindOfItem kind;

public:
    Item(int x, int y, kindOfItem kind);

    void setInactive();
    bool isActive() { return active; }
    kindOfItem getKind() { return kind; }

    virtual void update();
    virtual void draw();
    virtual void clean();

};



#endif
