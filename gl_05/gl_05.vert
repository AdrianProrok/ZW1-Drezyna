#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec3 vecColor;
out vec2 TexCoord;
out vec3 FragPos;
out vec3 Normal;

out vec4 PosForFog;
  
uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * transform * vec4(position, 1.0f);
	
	PosForFog = gl_Position;

	FragPos = vec3(transform * vec4(position, 1.0));

	Normal = vec3( transpose(inverse(transform)) * vec4(normal,1.0f) );  

	//float dis = distance( projection * view * vec4(lightPos,1.0f), gl_Position );
    //vecColor = vec4(color,1.0f) * 5.0f / dis;

	vecColor = color;
    TexCoord = texCoord;
} 