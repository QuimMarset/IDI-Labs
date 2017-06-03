#version 330 core

in vec3 fcolor;
out vec4 FragColor;

in vec3 matambFS;
in vec3 matdiffFS;
in vec3 matspecFS;
in float matshinFS;

in vec3 vertexFS;
in vec3 normalFS;
in vec4 vertexSCOFS;

// Valors per als components que necessitem dels focus de llum
uniform vec3 colFocus;
uniform vec3 llumAmbient;
uniform vec3 posFocus; 


vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matambFS;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiffFS * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if (dot(NormSCO,L) < 0)
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: normalize (2.0*dot(NormSCO,L)*NormSCO - L);
    vec3 V = normalize(-vertSCO.xyz);

    if ((dot(R, V) < 0) || (matshinFS == 0))
      return colRes;  // no hi ha component especular
    
    // Afegim la component especular
    float shine = pow(max(0.0, dot(R, V)), matshinFS);
    return (colRes + matspecFS * colFocus * shine); 
}


void main()
{	
	vec3 L = posFocus - vertexFS;
	L = normalize(L);
	vec3 normalFSN = normalize(normalFS);
	FragColor = vec4(Phong(normalFSN,L,vertexSCOFS),1.0);	
}
