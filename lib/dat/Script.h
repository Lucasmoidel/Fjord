#ifndef SCRIPT_H
#define SCRIPT_H

#include "../Fjord.h"

struct Script {
    bool ScriptEmpty = false;
    sol::environment env;
    std::string filePath;

    Script() : ScriptEmpty(true), filePath("") {}

    // Constructor for filePath
    Script(const std::string& path) : ScriptEmpty(false), filePath(path) {
        env = sol::environment(engine.lua, sol::create);
    }
};


#endif