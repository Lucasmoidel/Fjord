#include "Fjord.h"

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

    float wrapRotation(float angle) {
        // Ensure the angle is within 0 to 360
        while (angle < 0.0f) {
            angle += 360.0f;
        }
        while (angle >= 360.0f) {
            angle -= 360.0f;
        }
        return angle;
    }

    float lerp(float start, float end, float easing) {
        return start + easing * (end - start);
    }

    float toNDC_X(float x) {
    return (x / engine.screen_size.x) * 2.0f - 1.0f;
    }

    float toNDC_Y(float y) {
        return 1.0f - (y / engine.screen_size.y) * 2.0f;
    }


    std::vector<Vector2> rect(bool center_origin, int w, int h){
        std::vector<Vector2> points;
        if(!center_origin){
            points.push_back(Vector2(0, h));
            points.push_back(Vector2(w, h));
            points.push_back(Vector2(w, 0));
            points.push_back(Vector2(0, 0));
        } else {
            points.push_back(Vector2(-(w/2), h-(h/2)));
            points.push_back(Vector2(w-(w/2), h-(h/2)));
            points.push_back(Vector2(w-(w/2), -(h/2)));
            points.push_back(Vector2(-(w/2), -(h/2)));
        }

        return points;
    }
}