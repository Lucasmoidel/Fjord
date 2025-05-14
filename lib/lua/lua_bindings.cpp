#include "../Fjord.h"

void LuaHandler::bindToLuaState(sol::state *lua) {
    lua->open_libraries(sol::lib::base, sol::lib::math, sol::lib::table, sol::lib::string, sol::lib::io);

    // Bind Vector2 Enums
    sol::table vector_enum = lua->create_named_table("VectorEnum");
    vector_enum["ZERO"] = VectorEnum::ZERO;

    // Bind Vector2
    lua->new_usertype<Vector2>("Vector2",
        sol::constructors<
            Vector2(float, float),
            Vector2(VectorEnum)
        >(),
        "x", &Vector2::x,
        "y", &Vector2::y,
        "ZERO", sol::var(Vector2::ZERO)
    );

    // Bind Color
    lua->new_usertype<Color>("Color",
        sol::constructors<Color(float, float, float, float)>(),
        "r", &Color::r,
        "g", &Color::g,
        "b", &Color::b,
        "a", &Color::a
    );

    // Bind Shape
    lua->new_usertype<Shape>("Shape",
        sol::constructors<Shape()>(),
        "shape", &Shape::shape,
        "setShape", &Shape::setShape
    );

    // Bind Transform
    lua->new_usertype<Transform>("Transform",
        sol::constructors<Transform()>(),
        "position", &Transform::position,
        "global_position", &Transform::global_position,
        "scale", &Transform::scale,
        "global_scale", &Transform::global_scale,
        "rotation", &Transform::rotation,
        "global_rotation", &Transform::global_rotation
    );

    // Bind Node
    lua->new_usertype<Node>("Node",
        sol::constructors<Node()>(),
        "transform", &Node::transform,
        //Define Functions
        "get_node", &Node::get_node
    );

    // Bind Polygon
    lua->new_usertype<Polygon>("Polygon",
        sol::constructors<Polygon()>(),
        sol::base_classes, sol::bases<Node>(),
        "color", &Polygon::color,
        "shape", &Polygon::shape
    );
}