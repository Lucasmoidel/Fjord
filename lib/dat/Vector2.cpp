#include <iostream>
#include "../Fjord.h"

Vector2::Vector2(float xPos, float yPos) : x(xPos), y(yPos) {
    x = xPos;
    y = yPos;
}

Vector2::Vector2(VectorEnum vecEnum){
    switch (vecEnum) {
        case VectorEnum::ZERO:
            x = 0;
            y = 0;
    }
}

const Vector2 Vector2::ZERO(Vector2::ZERO);

Vector2 Vector2::operator+(const Vector2& other) const { // Vector2 Add Operation
    return Vector2(x+other.x, y+other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const { // Vector2 Subtract Operation
    return Vector2(x-other.x, y-other.y);
}

Vector2 Vector2::operator*(const Vector2& other) const {
    return Vector2(x*other.x, y*other.y);
}

Vector2 Vector2::operator*(int scalar) const { // Vector2 Multiply by Int
    return Vector2(this->x*scalar,this->y*scalar);
}

Vector2 Vector2::operator*(float scalar) const { // Vector2 Multiply by Int
    return Vector2(this->x*scalar,this->y*scalar);
}

Vector2& Vector2::operator=(const Vector2& other) {
    if (this != &other){
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2& Vector2::operator+=(const Vector2& other) { // Vector2 Add Equals Operation
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) { // Vector2 Subtract Equals Operation
    x -= other.x;
    y -= other.y;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector2& vec) { // Vector2 STD::Cout Operation
     os << "Vector2(" << vec.x << ", " << vec.y << ")"; 
     return os;
}