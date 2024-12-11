#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace Utilities
{
    int ClampI(int numberToClamp,int minValue, int maxValue){
        if ( numberToClamp < minValue){ return minValue; } else if ( numberToClamp > maxValue){ return maxValue;} else {  return numberToClamp; }
    }
    
   float ClampF(float numberToClamp, float minValue, float maxValue){
        if ( numberToClamp < minValue){ return minValue; } else if ( numberToClamp > maxValue){ return maxValue;} else {  return numberToClamp; }
    }

    std::vector<std::string> SplitString(std::string input, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = input.find(delimiter, pos_start)) != std::string::npos) {
            token = input.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (input.substr (pos_start));
        return res;
    }
}