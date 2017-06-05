#version 330 core

out vec4 FragColor;
in vec3 colorO;

void main() {
    FragColor = vec4(colorO, 1.0);
  
}

