
#ifndef Item_h
#define Item_h

#include <stdio.h>
#include "Game.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL2/SDL.h>

enum kindOfItem {
    item_accelerate, item_decelerate, item_growBall, item_shrinkBall, item_growPaddle, item_shrinkPaddle
};

class Item : public GameObject {

private:
    bool active;
    kindOfItem kind;
    SDL_Color itemColor;
    SDL_Point trigPoints[4];
    void updateLines();

public:
    Item(kindOfItem kind);

    void setInactive();
    void setActive(float x, float y);
    bool isActive() { return active; }
    kindOfItem getKind() { return kind; }

    virtual void update();
    virtual void draw();
    virtual void clean();

};



#endif
