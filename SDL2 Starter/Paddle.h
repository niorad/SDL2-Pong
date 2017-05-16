#ifndef Paddle_h
#define Paddle_h

#include <stdio.h>
#include <string>
#include "GameObject.h"

class Paddle : public GameObject {

private:
    bool isMovingDown;
    bool isMovingUp;
    float targetSpeed;
    float currentSpeed;
    float speed;
    float acceleration;
    bool isBlue;

public:

    Paddle(int X, int Y, int W, int H, bool isPlayer);
    virtual void draw();
    virtual void update();
    virtual void clean();

    void startMovingUp();
    void startMovingDown();
    void stopMovingUp();
    void stopMovingDown();
    void setCenterY(float y);
    void grow(float amount);
    void shrink(float amount);

};
#endif
