#version 330 core

out vec4 FragColor;
in vec3 colorO;

void main() {
    //FragColor = vec4(colorO, 1);
    int modul = int(gl_FragCoord.y)%20;
    if (modul > 10) discard;
    else {
        if (gl_FragCoord.x < 357 && gl_FragCoord.y < 357) FragColor = vec4(1,0,0,1);
        else if (gl_FragCoord.x < 357 && gl_FragCoord.y > 357) FragColor = vec4(0.0,1.0,0.0,1.0);
        else if (gl_FragCoord.x > 357 && gl_FragCoord.y < 357) FragColor = vec4(0.0,0.0,1.0,1.0);
        else FragColor = vec4(1.0,1.0,0.0,1.0);
    }
}

