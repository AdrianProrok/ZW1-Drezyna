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
uniform bool isTextured;
uniform float ambientStrength;

#define NR_LIGHTS 100

uniform vec3 lightPos[NR_LIGHTS];
uniform vec3 lightColor[NR_LIGHTS];
uniform float lightIntens[NR_LIGHTS];

void main()
{
	//color = texture(DiffTexture, TexCoord) * vec4(vecColor,1.0);
	if( selfIllumination ) {
		if( isTextured)
			color =  texture(DiffTexture, TexCoord);
		else
			color = vec4(vecColor,1.0);
	}
	else {
		// ambient
		//float ambientStrength = 0.2;
		vec3 ambient = ambientStrength * vec3(1,1,1);
		vec3 result = vec3(0,0,0);
		for(int i = 0; i < numberOfLights; i++) {  	
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
		
		float fog = (PosForFog.z / 600.0);
		fog = clamp(fog, 0.0, 1.0);

		color = mix(color, vec4(1.0, 1.0, 1.0, 1.0), fog );
	}
}
// vec4(0.2, 0.35, 0.7, 1.0)
// specular
    //float specularStrength = 0.5;
    //vec3 viewDir = normalize(viewPos - FragPos);
    //vec3 reflectDir = reflect(-lightDir, norm);  
    //float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //vec3 specular = specularStrength * spec * lightColor;  