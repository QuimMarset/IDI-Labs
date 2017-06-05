#version 330 core

in vec3 fcolor;
out vec4 FragColor;

uniform int pintaFranges;


void main()
{	
	if (pintaFranges == 1) {
		int modul = int(gl_FragCoord.y)%20;
		if (modul < 10) {
			FragColor = vec4(0,0,0,1);
		}
		else {
			FragColor = vec4(1,1,1,1);
		}
	}
	else {
		FragColor = vec4(fcolor,1);
	}
	

}
