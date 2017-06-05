#include "MyGLWidget.h"
#include <QKeyEvent>
#include <QMouseEvent>
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
  tx = 0.0;
  ty = 0.0;
  factorY = 1.0;
  factorX = 1.0;
  
}

void MyGLWidget::paintGL ()
{
  glClear (GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer
  // Activem l'Array a pintar 
  glBindVertexArray(VAO);
  
  // Pintem l'escena
  glDrawArrays(GL_TRIANGLES, 0, 3);
  
  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport (0, 0, w, h);
}

void MyGLWidget::createBuffers ()
{
  glm::vec3 Vertices[3];  // Tres vèrtexs amb X, Y i Z
  Vertices[0] = glm::vec3(-1.0, -1.0, 0.0);
  Vertices[1] = glm::vec3(1.0, -1.0, 0.0);
  Vertices[2] = glm::vec3(0.0, 1.0, 0.0);
  
  glm::vec3 colorsVertex[3];
  colorsVertex[0] = glm::vec3(1,0,0);
  colorsVertex[1] = glm::vec3(0,1,0);
  colorsVertex[2] = glm::vec3(0,0,1);
  
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  
  glGenBuffers(2, VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex	
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colorsVertex),colorsVertex, GL_STATIC_DRAW);
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  // Desactivem el VAO
  glBindVertexArray(0);
}

void MyGLWidget::modelTransform() {
 
    glm::mat4 TG(1.0);
    TG = glm::translate(TG,glm::vec3(tx,ty,0.0));
    TG = glm::scale(TG,glm::vec3(factorX,factorY,1.0));
    //TG = glm::rotate(TG,float(M_PI/4),glm::vec3(0,0,1));
    
    glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
    
}


void MyGLWidget::keyPressEvent (QKeyEvent *e) {
    makeCurrent ();
    switch ( e->key() ) {
    case Qt::Key_Up :
        ty += 0.1;
        modelTransform();
        break;
    case Qt::Key_Down :
        ty -= 0.1;
        modelTransform();
        break;
        
    case Qt::Key_Left :
        tx -= 0.1;
        modelTransform();
        break;
    case Qt::Key_Right :
        tx += 0.1;
        modelTransform();
        break;
    default: e->ignore (); // propagar al pare
    }
    update ();
}

void MyGLWidget::mouseMoveEvent ( QMouseEvent * e ) {
    makeCurrent ();
    if (e->x() > xAnt) factorX = (factorX + 0.1 >= 5.0) ? 5.0:factorX + 0.1;
    else if (e->x() < xAnt) factorX = (factorX - 0.1 <= 1.0) ? 1.0:factorX-0.1;
    //if (e->y() > yAnt) factorY = (factorY + 0.1 >= 2.0) ? 2.0:factorY + 0.1;
    //else if (e->y() < yAnt) factorY = (factorY - 0.1 <= 1.0) ? 1.0:factorY-0.1;

    modelTransform();
    
    update ();
}

void MyGLWidget::mousePressEvent(QMouseEvent* e) {
    makeCurrent();
    xAnt = e->x();
    yAnt = e->y();
    update();
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
  glm::mat4 TG (1.0); // Matriu de transformació, inicialment identitat
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
  
}
