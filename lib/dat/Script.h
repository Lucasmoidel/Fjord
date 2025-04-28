#ifndef SCRIPT_H
#define SCRIPT_H

#include "../Fjord.h"

struct Script {
    bool ScriptEmpty = true;
    sol::environment env;
    std::string filePath;

    Script() : ScriptEmpty(true), filePath("") {}

    // Constructor for filePath
    Script(const std::string& path, const sol::state* lua) : ScriptEmpty(false), filePath(path) {
        env = sol::environment(*lua, sol::create, lua->globals());
    }
};


#endif