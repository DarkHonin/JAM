#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 Normal;
layout (location = 2) in vec3 FragColour;
layout (location = 3) in vec2 TextureCoord;

out vec4 col;

uniform mat4    projection;

struct Components{
    vec3 	p, o, s;	
};
uniform position{
    Components components;
    mat4	modelMatrix;
} positionData;

void main()
{
    col = vec4(FragColour, 1.0f);
    gl_Position = vec4(aPos, 1.0) * positionData.modelMatrix;
}