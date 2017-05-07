//
//  Button.hpp
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 06.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp
#pragma once

#include <stdio.h>
#include "GameObject.h"

class Button : public GameObject {

public:

    Button(string TEX_ID, int X, int Y, int W, int H, int SCALE);

    virtual void draw();
    virtual void update();
    virtual void clean();

private:

    bool released;
    enum button_state {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        MOUSE_DOWN = 2
    };
};



#endif /* Button_hpp */
