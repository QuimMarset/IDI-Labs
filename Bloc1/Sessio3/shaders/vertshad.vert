#version 330 core

in vec3 vertex;
in vec3 colorI;
out vec3 colorO;
uniform mat4 TG;

void main()  {
    gl_Position = TG*vec4 (0.5*vertex, 1.0);
    colorO = colorI;
}
