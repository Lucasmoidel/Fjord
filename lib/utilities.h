#ifndef UTILITIES_H
#define UTILITIES_H

#include "Fjord.h"
namespace Utilities {
    int ClampI(int numberToClamp,int minValue, int maxValue);
    float ClampF(float numberToClamp,float minValue, float maxValue);

    std::vector<std::string> SplitString(std::string input, std::string delimiter);
}

#endif
