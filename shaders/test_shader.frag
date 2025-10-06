// Test fragment shaders 
#version 450

// from vertex shader input 
layout( location = 0 ) in vec3 fragColor;
layout( location = 1 ) in vec2 textCoord;

// output to frame buffer 
layout( location = 0 ) out vec4 outColor;

// sampler input
layout( binding = 0 ) uniform sampler2D samp0;

void main( void )
{
#if 0
    outColor = vec4( fragColor, 1.0 );
#else
    outColor = texture( samp0, textCoord );
#endif
}
