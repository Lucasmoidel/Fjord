#ifndef COLOR_H
#define COLOR_H
#include "../Fjord.h"

struct Color {
    float r = 0;
    float g = 0;
    float b = 0;
    float a = 0;

    Color(float r=0, float g=0, float b=0, float a=0) : r(r), g(g), b(b), a(a) {}

};

#endif