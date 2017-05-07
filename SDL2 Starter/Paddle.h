//
//  Paddle.hpp
//  SDL2 Pong
//
//  Created by Antonio Radovcic on 07.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef Paddle_hpp
#define Paddle_hpp

#include <stdio.h>
#include <string>
#include "GameObject.h"

class Paddle : public GameObject {

private:
    SDL_Rect body;
public:

    Paddle(string TEX_ID, int X, int Y, int W, int H, int SCALE);
    virtual void draw();
    virtual void update();
    virtual void clean();

    virtual void moveUp();
    void moveDown();

};



#endif /* Paddle_hpp */
