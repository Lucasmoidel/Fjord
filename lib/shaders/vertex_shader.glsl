#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

out vec4 vertexColor; // Output to the fragment shader

void main()
{
    gl_Position = vec4(position, 1.0); // Transform position to clip space
    vertexColor = color;              // Pass the color to the next stage
}
