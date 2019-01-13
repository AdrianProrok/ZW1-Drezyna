#version 330 core
in vec3 vecColor;
in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;  

out vec4 color;

uniform sampler2D Texture0;
uniform sampler2D Texture1;

uniform int numberOfLights;
uniform bool selfIllumination;
uniform float ambientStrength;

#define NR_LIGHTS 100

uniform vec3 lightPos[NR_LIGHTS];
uniform vec3 lightColor[NR_LIGHTS];
uniform float lightIntens[NR_LIGHTS];

void main()
{
	/* color = mix(texture(Texture0, TexCoord), texture(Texture1, TexCoord),0.4) * vecColor; */
	if( selfIllumination )
		color = vec4(vecColor,1.0);
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
			result += diffuse * vecColor;
		}

		result += ambient * vecColor;
		color = vec4(result, 1.0);
	}
}

// specular
    //float specularStrength = 0.5;
    //vec3 viewDir = normalize(viewPos - FragPos);
    //vec3 reflectDir = reflect(-lightDir, norm);  
    //float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //vec3 specular = specularStrength * spec * lightColor;  