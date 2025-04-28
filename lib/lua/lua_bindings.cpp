#include "../Fjord.h"

void LuaHandler::bindToLuaState(sol::state *lua){

    // Bind Vector2 Enums
    sol::table vector_enum = lua->create_named_table("VectorEnum");
    vector_enum["ZERO"] = VectorEnum::ZERO;

    // Bind Vector2
    sol::usertype<Vector2> vector2_type = lua->new_usertype<Vector2>("Vector2",
        sol::constructors<
            Vector2(float,float),
            Vector2(VectorEnum)
            >(),

        "x", &Vector2::x,
        "y", &Vector2::y,

        "ZERO", sol::var(Vector2::ZERO)
    );
}