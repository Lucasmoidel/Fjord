#ifndef UTILITIES_H
#define UTILITIES_H

#include "Fjord.h"

namespace Util {
    int ClampI(int numberToClamp,int minValue, int maxValue);
    float ClampF(float numberToClamp,float minValue, float maxValue);

    std::vector<std::string> SplitString(std::string input, std::string delimiter);

    float wrapRotation(float angle);

    float lerp(float start,float end,float easing);

    float toNDC_X(float x);
    float toNDC_Y(float y);

    std::vector<Vector2> rect(bool center_origin, int w, int h);

    int center(int a, int b);

}

#endif
