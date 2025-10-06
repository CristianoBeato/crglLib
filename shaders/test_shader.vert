// test vertex shder
#version 450

// vertex attribs input 
layout( location = 0 ) in vec3 inPosition;
layout( location = 1 ) in vec2 inTcoord;
layout( location = 2 ) in vec3 inColor;

// fragment shader outpur
layout( location = 0 ) out vec3 fragColor;
layout( location = 1 ) out vec2 textCoord;

void main() 
{
    gl_Position = vec4( inPosition, 1.0);
    textCoord = inTcoord;
    fragColor = inColor;
}
