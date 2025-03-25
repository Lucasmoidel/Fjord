#ifndef Fjord_H
#define Fjord_H

#include <nlohmann/json.hpp>

//cpp libs
#include <iostream> 
#include <vector>
#include <array>
#include <fstream>
#include <stdexcept>
#include <sstream>

//SDL libs
#include <SDL3/SDL.h>
//#include <SDL3/SDL_ttf.h>

//Fjord libs
#include "utilities.h"
#include "dat/Input.h"
#include "dat/Vector2.h"
#include "dat/Transform.h"
#include "node/Node.h"
#include "dat/shape.h"
#include "node/Polygon.h"

class Engine {
    public:
        bool create_window(std::string title, Vector2 size);
};

#endif // MYHEADER_H