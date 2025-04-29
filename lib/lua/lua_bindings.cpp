#include "../Fjord.h"

void LuaHandler::bindToLuaState(sol::state *lua){

    lua->open_libraries(sol::lib::base, sol::lib::math, sol::lib::table, sol::lib::string, sol::lib::io);

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

    lua->new_usertype<Color>("Color",

        sol::constructors<
            Color(float,float,float,float)
        >(),

        "r", &Color::r,
        "g", &Color::g,
        "b", &Color::b,
        "a", &Color::b
    );

    lua->new_usertype<Shape>("Shape",

        "shape", &Shape::shape,
        // Shape Functions
        "setShape", &Shape::setShape
    );

    lua->new_usertype<Transform>("Transform",
        "position", &Transform::position,
        "global_position", &Transform::global_position,

        "scale", &Transform::scale,
        "global_scale", &Transform::global_scale,

        "rotation", &Transform::rotation,
        "global_rotation", &Transform::global_rotation
    );

    lua->new_usertype<Node>("Node",
        "transform", &Node::transform
    );

    lua->new_usertype<Polygon>("Polygon",
        //sol::constructors<Polygon()>(),
        "color", &Polygon::color,
        "shape", &Polygon::shape,
        sol::bases<Node>()
    );
}