#version 330 core

layout(location = 0) in vec2 position; // Changed to vec2
layout(location = 1) in vec4 color;

uniform mat4 projection;
out vec4 vertexColor;

void main()
{
    gl_Position = projection * vec4(position, 0.0, 1.0); // Set z = 0
    vertexColor = color;
}