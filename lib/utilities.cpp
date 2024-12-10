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
        std::vector<std::string> result;

        std::istringstream data(input);
        std::string line;
        while(std::getline(data,line,delimiter)){

        }
    }
} // namespace Utilities
