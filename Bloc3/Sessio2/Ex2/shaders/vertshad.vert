#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

out vec3 matambFS;
out vec3 matdiffFS;
out vec3 matspecFS;
out float matshinFS;

out vec3 vertexFS;
out vec3 normalFS;
out vec4 vertexSCOFS;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;



void main()
{	

    vec3 vertexSCO = vec3(view*TG*vec4(vertex,1.0));
    vertexFS = vertexSCO;
   
    mat3 NormalMatrix = inverse (transpose (mat3 (view * TG)));
    vec3 normalSCO = NormalMatrix*normal;
    normalSCO = normalize(normalSCO);
    normalFS = normalSCO;

    vec4 vertexSCOPhong = vec4(view*TG*vec4(vertex,1.0));
    vertexSCOFS = vertexSCOPhong;

    matambFS = matamb;
    matdiffFS = matdiff;
    matspecFS = matspec;
    matshinFS = matshin;



    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}
