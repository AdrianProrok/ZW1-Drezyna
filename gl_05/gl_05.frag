#version 330 core
in vec3 vecColor;
in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;  

out vec4 color;

uniform sampler2D Texture0;
uniform sampler2D Texture1;

uniform vec3 lightPos;
uniform vec3 lightColor;

void main()
{
	/* color = mix(texture(Texture0, TexCoord), texture(Texture1, TexCoord),0.4) * vecColor; */
	//color = vecColor;


	// ambient
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
	vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

	diffuse = diffuse * ( 15.0f / distance(lightPos, FragPos) );
    
    // specular
    //float specularStrength = 0.5;
    //vec3 viewDir = normalize(viewPos - FragPos);
    //vec3 reflectDir = reflect(-lightDir, norm);  
    //float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //vec3 specular = specularStrength * spec * lightColor;  
        
    vec3 result = (ambient + diffuse) * vecColor;
    color = vec4(result, 1.0);
}
