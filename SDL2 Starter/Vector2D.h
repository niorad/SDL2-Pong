//
//  Vector2D.h
//  SDL2 Starter
//
//  Created by Antonio Radovcic on 03.05.17.
//  Copyright © 2017 niorad. All rights reserved.
//

#ifndef Vector2D_h
#define Vector2D_h


#pragma once

#include <math.h>

class Vector2D {

public:

    Vector2D(float X, float Y) : x(X), y(Y) {}
    
    float getX() { return x; }
    float getY() { return y; }
    
    void setX(float X) { x = X; }
    void setY(float Y) { y = Y; }
    
    float length() { return sqrt(x * x + y * y); }
    
    Vector2D operator+(const Vector2D& v2) const {
        return Vector2D(x + v2.x, y + v2.y);
    }
    
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        
        return v1;
    }
    
    Vector2D operator*(float scalar)
    {
        return Vector2D(x * scalar, y * scalar);
    }
    
    Vector2D& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        
        return *this;
    }
    
    Vector2D operator-(const Vector2D& v2) const
    {
        return Vector2D(x - v2.x, y - v2.y);
    }
    
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        
        return v1;
    }
    
    Vector2D operator/(float scalar)
    {
        return Vector2D(x / scalar, y / scalar);
    }
    
    Vector2D& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        
        return *this;
    }
    
    void normalise()
    {
        float l = length();
        if (l > 0)
        {
            (*this) *= 1 / 1;
        }
    }
    
private:
    
    float x, y;
};



#endif /* Vector2D_h */
