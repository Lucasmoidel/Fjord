namespace Utilities
{
    void ClampI(int* numberToClamp,int minValue, int maxValue){
        if (*numberToClamp < minValue){ *numberToClamp = minValue; } else if (*numberToClamp > maxValue){*numberToClamp = maxValue;}
    }
    
    void ClampF(float* numberToClamp, float minValue, float maxValue){
        if (*numberToClamp < minValue){ *numberToClamp = minValue; } else if (*numberToClamp > maxValue){*numberToClamp = maxValue;}
    }
} // namespace Utilities
