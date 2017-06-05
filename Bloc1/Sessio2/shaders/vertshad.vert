#version 330 core

in vec3 vertex;
in vec3 colorI;
out vec3 colorO;

void main()  {
    gl_Position = vec4 (0.5*vertex, 1.0);
    colorO = colorI;
}
