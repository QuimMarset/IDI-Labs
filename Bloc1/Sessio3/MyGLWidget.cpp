#include "MyGLWidget.h"
#include <QKeyEvent>
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"




MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent)
{
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();
  
  glClearColor (0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  createBuffers();
  angle = 0.0;
  angle2 = 0.0;
 
}

void MyGLWidget::paintGL ()
{
  glClear (GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer
  // Activem l'Array a pintar 
  glBindVertexArray(VAO[0]);
  // Pintem l'escena
  modelTransform(0);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);
  // Desactivem el VAO
  glBindVertexArray(VAO[1]);
  modelTransform(1);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glBindVertexArray(0);
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport (0, 0, w, h);
}

void MyGLWidget::createBuffers ()
{

    glm::vec3 colorsVertex[3];
    colorsVertex[0] = glm::vec3(1,0,0);
    colorsVertex[1] = glm::vec3(0,1,0);
    colorsVertex[2] = glm::vec3(0,0,1);
        
        
    glm::vec3 Vertices[5];  // Tres vèrtexs amb X, Y i Z
    Vertices[0] = glm::vec3(-0.5, -1.0, 0.0);
    Vertices[1] = glm::vec3(0.5, -1.0, 0.0);
    Vertices[2] = glm::vec3(-0.5, 0.0, 0.0);
    Vertices[3] = glm::vec3(0.5, 0.0, 0.0);
    Vertices[4] = glm::vec3(0.0, 0.5, 0.0);

    // Creació del Vertex Array Object (VAO) que usarem per pintar
    glGenVertexArrays(2, VAO);
    glBindVertexArray(VAO[0]);

    // Creació del buffer amb les dades dels vèrtexs
    glGenBuffers(4, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // Activem l'atribut que farem servir per vèrtex	
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colorsVertex), colorsVertex, GL_STATIC_DRAW);
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    // Desactivem el VAO
    //glBindVertexArray(0);
    
    glm::vec3 VertexQuad[4];
    VertexQuad[0] = glm::vec3(0.5, 0.5, 0.0);
    VertexQuad[1] = glm::vec3(1.0, 0.5, 0.0);
    VertexQuad[2] = glm::vec3(0.5, 1.0, 0.0);
    VertexQuad[3] = glm::vec3(1.0, 1.0, 0.0);
    
    
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER,VBO[1]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(VertexQuad),VertexQuad,GL_STATIC_DRAW);
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colorsVertex), colorsVertex, GL_STATIC_DRAW);
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);
    
    glBindVertexArray(0);
}

void MyGLWidget::modelTransform(int index) {
 
    glm::mat4 TG(1.0);
    if (index == 0) {
        TG = translate(TG,glm::vec3(0.0,-0.125,0));
        TG = rotate(TG,angle,glm::vec3(0,0,1));
        TG = translate(TG,glm::vec3(0.0,0.125,0));
        
    }
    else {
        TG = translate(TG,glm::vec3(0.375,0.375,0));
        TG = rotate(TG,angle2,glm::vec3(0,0,1));
        TG = translate(TG,glm::vec3(-0.375,-0.375,0));
    }
    glUniformMatrix4fv(transLoc,1,GL_FALSE,&TG[0][0]);
    
}


void MyGLWidget::keyPressEvent (QKeyEvent *e) {
    makeCurrent ();
    switch ( e->key() ) {
        case Qt::Key_P:
            angle += float(M_PI/6);
            angle2 -= float(M_PI/6);
            break;
    default: e->ignore (); // propagar al pare
    }
    update ();
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/fragshad.frag");
  vs.compileSourceFile("shaders/vertshad.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  colorLoc = glGetAttribLocation(program->programId(),"colorI");
  transLoc = glGetUniformLocation(program->programId(),"TG");
  glm::mat4 TG(1.0);
  glUniformMatrix4fv(transLoc,1,GL_FALSE,&TG[0][0]);
  
}
