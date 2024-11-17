namespace Utilities
{
    int ClampI(int numberToClamp,int minValue, int maxValue){
        if (numberToClamp < minValue){ return minValue;} else if (numberToClamp>maxValue){return maxValue;}else{return numberToClamp;}
    }
    
    float ClampF(float numberToClamp, float minValue, float maxValue){
        if (numberToClamp < minValue){ return minValue;} else if (numberToClamp>maxValue){return maxValue;}else{return numberToClamp;}
    }
} // namespace Utilities
