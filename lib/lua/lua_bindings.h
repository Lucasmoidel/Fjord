#ifndef LUA_BINDINGS_H
#define LUA_BINDINGS_H

#include "../Fjord.h"

class LuaHandler {
    public:
        void bindToLuaState(sol::state *lua);
};

#endif