#ifndef Vector2_H
#define Vector2_H

class Vector2 {
    public:
        float x;
        float y;

        Vector2(float xPos=0,float yPos=0);

        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        
        friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);
};

#endif