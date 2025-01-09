#ifndef Vector2_H
#define Vector2_H

#include "../Fjord.h"

enum class VectorEnum {
    ZERO
};

class Vector2 {
    public:
        float x;
        float y;

        //b2Vec2* BOX = {reinterpret_cast<float*>(&x),reinterpret_cast<float*>(&y)};

        Vector2(float xPos=0,float yPos=0);

        b2Vec2 box();

        Vector2(VectorEnum VectorEnum);

        static const Vector2 ZERO;

        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;

        Vector2 operator*(const Vector2& other) const; // Vec2 times Vec2

        Vector2 operator*(int scalar) const; // Vec2 times Int
        Vector2 operator*(float scalar) const; // Vec2 time Float
        // Todo: Vec2 times Double

        friend Vector2 operator*(int scalar,const Vector2& vec);
        friend Vector2 operator*(float scalar,const Vector2& vec);

        Vector2& operator=(const Vector2& other);

        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        
        friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);
};

#endif