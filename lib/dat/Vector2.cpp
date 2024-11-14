#include <iostream>
#include "../Fjord.h"

Vector2::Vector2(float xPos, float yPos) : x(xPos), y(yPos) {
    x = xPos;
    y = yPos;
}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x+other.x, y+other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x-other.x, y-other.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
     os << "Vector2(" << vec.x << ", " << vec.y << ")"; 
     return os;
}