#version 330 core
in vec3 vecColor;
in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;  

in vec4 PosForFog;

out vec4 color;

uniform sampler2D DiffTexture;

uniform int numberOfLights;
uniform bool selfIllumination;
uniform float selfIlluminationIntens;
uniform bool isTextured;
uniform float ambientStrength;

#define NR_LIGHTS 200

uniform vec3 lightPos[NR_LIGHTS];
uniform vec3 lightColor[NR_LIGHTS];
uniform float lightIntens[NR_LIGHTS];

void main()
{
	float ambient_normalize = ambientStrength/1.0 + lightIntens[0]/45000000.0;
	ambient_normalize = clamp(ambient_normalize,0.0,1.0);

	if( selfIllumination ) {
		if( isTextured) {
			color = vec4( vec3(texture(DiffTexture, TexCoord)) * ambient_normalize, 1.0 );
		}
		else {
			color = vec4(vecColor * clamp(selfIlluminationIntens,0.0,1.0), 1.0);
		}
	}
	else {
		vec3 ambient = ambientStrength * vec3(1,1,1);
		vec3 result = vec3(0,0,0);
		for(int i = 0; i < numberOfLights && i < NR_LIGHTS; i++) {  	
			// diffuse 
			vec3 norm = normalize(Normal);
			vec3 lightDir = normalize(lightPos[i] - FragPos);
			float diff = max(dot(norm, lightDir), 0.0);
			vec3 diffuse = diff * lightColor[i];

			diffuse = diffuse * ( lightIntens[i] / (distance(lightPos[i], FragPos)*distance(lightPos[i], FragPos)) );
			if( isTextured)
				result += diffuse * vec3(texture(DiffTexture, TexCoord));
			else
				result += diffuse * vecColor;
		}
		if( isTextured )
			result += ambient * vec3(texture(DiffTexture, TexCoord));
		else
			result += ambient * vecColor;
		color = vec4(result, 1.0);
		
		float fog = ((PosForFog.z-100) / 500.0) * ambient_normalize;
		fog = clamp(fog, 0.0, 1.0);

		color = mix(color, vec4(0.463, 0.431, 0.451, 1), fog );
	}
}