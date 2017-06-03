#include "MyGLWidget.h"

#include <iostream>
using namespace std;
#include <cmath>


MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent)
{
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
  scale = 1.0f;
  angleRotacio = 0.0f;
  rav = 1.0f;
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
  glEnable(GL_DEPTH_TEST);
  model.load("../../Models/HomerProves.obj");
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  createBuffers();
  calculaParametres();
  iniCamera();
}

void MyGLWidget::paintGL () 
{
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Carreguem la transformació de model
  modelTransformHomer ();

  // Activem el VAO per a pintar la caseta 
  glBindVertexArray (VAO_Homer);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, model.faces().size()*3);

  modelTransformTerra();
  glBindVertexArray(VAO_Terra);
  glDrawArrays(GL_TRIANGLES,0,6);

  glBindVertexArray (0);
}

void MyGLWidget::modelTransformHomer () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  //transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::rotate(transform, angleRotacio, glm::vec3(0,1,0));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformTerra() {
  glm::mat4 transform(1.0f);
  glUniformMatrix4fv(transLoc,1,GL_FALSE,&transform[0][0]);
}

void MyGLWidget::calculaParametres() {

  puntMaximCapsaEscena = glm::vec3(2.0f,1.0f,2.0f);
  puntMinimCapsaEscena = glm::vec3(-2.0f,-1.0f,-2.0f);

  float xmin,xmax,ymin,ymax,zmin,zmax;
  xmin = xmax = model.vertices()[0];
  ymin = ymax = model.vertices()[1];
  zmin = zmax = model.vertices()[2];


  for (unsigned int i = 3;i < model.vertices().size();i+= 3) {
      if (model.vertices()[i] > xmax) xmax = model.vertices()[i];
      else if (model.vertices()[i] < xmin) xmin = model.vertices()[i];

      if (model.vertices()[i+1] > ymax) ymax = model.vertices()[i+1];
      else if (model.vertices()[i+1] < ymin) ymin = model.vertices()[i+1];

      if (model.vertices()[i+2] > zmax) zmax = model.vertices()[i+2];
      else if (model.vertices()[i+2] < zmin) zmin = model.vertices()[i+2];
  }

  puntMaximCapsaModel = glm::vec3(xmax,ymax,zmax);
  puntMinimCapsaModel = glm::vec3(xmin,ymin,zmin);

  centreBaseCapsaModel = glm::vec3((xmax+xmin)/2.0f, ymin, (zmax+zmin)/2.0f);

  centreCapsaModel = glm::vec3((xmax+xmin)/2.0f, (ymax+ymin)/2.0f, (zmax+zmin)/2.0f);


  radiEsfera = sqrt(pow(puntMaximCapsaEscena.x - puntMinimCapsaEscena.x,2) + pow(puntMaximCapsaEscena.y - puntMinimCapsaEscena.y,2) 
    + pow(puntMaximCapsaEscena.z - puntMinimCapsaEscena.z,2));
  radiEsfera = radiEsfera/2.0f;


}

void MyGLWidget::iniCamera() {

   dist = 2*radiEsfera;

  OBS = glm::vec3(0,0,dist);
  VRP = glm::vec3(0,0,0);
  UP = glm::vec3(0,1,0);

  zN = radiEsfera;
  zF = 3*radiEsfera;
  angleCamera = asin(radiEsfera/dist);
  
  rav = (float)width()/(float)height();

  projectTransform();
  viewTransform();

}


void MyGLWidget::projectTransform() {

  glm::mat4 project;
  
  if (rav >= 1.0f) {
    project = glm::perspective(2*angleCamera,rav,zN,zF);
  }
  else {
    float angleNou = atan(tan(angleCamera)/rav);
    project = glm::perspective(2*angleNou,rav,zN,zF);
  }
  
  glUniformMatrix4fv(projLoc,1,GL_FALSE,&project[0][0]);
}

void MyGLWidget::viewTransform() {

  glm::mat4 view = glm::lookAt(OBS,VRP,UP);
  glUniformMatrix4fv(viewLoc,1,GL_FALSE,&view[0][0]);
}


void MyGLWidget::resizeGL (int w, int h) 
{
  rav = float(w)/float(h);
  projectTransform();
  glViewport(0, 0, w, h);
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }

    case Qt::Key_R: {
      angleRotacio += (float)M_PI/4.0f;
      if (angleRotacio == (float)2.0f*M_PI) angleRotacio = 0.0f;
    }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::createBuffers () 
{
  // Dades de la caseta
  // Dos VBOs, un amb posició i l'altre amb color
  glm::vec3 posicio[6] = {
	glm::vec3(-2.0, -1.0, 2.0),
	glm::vec3( 2.0, -1.0, 2.0),
	glm::vec3(-2.0, -1.0, -2.0),
	glm::vec3(-2.0, -1.0, -2.0),
	glm::vec3( 2.0, -1.0, 2.0),
  glm::vec3( 2.0, -1.0, -2.0),
  }; 
  glm::vec3 color[6] = {
	glm::vec3(0,0,1),
	glm::vec3(0,0,1),
	glm::vec3(0,0,1),
	glm::vec3(0,0,1),
  glm::vec3(0,0,1),
	glm::vec3(0,0,1)
  };

  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Homer);
  glBindVertexArray(VAO_Homer);

  glGenBuffers(1, &VBO_HomerPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*model.faces().size()*3*3, model.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_HomerCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerCol);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*model.faces().size()*3*3, model.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);


  glGenVertexArrays(1,&VAO_Terra);
  glBindVertexArray(VAO_Terra);

  glGenBuffers(1, &VBO_TerraPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraPos);
  glBufferData(GL_ARRAY_BUFFER,sizeof(posicio), posicio, GL_STATIC_DRAW);

  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0 , 0);
  glEnableVertexAttribArray(vertexLoc);


  glGenBuffers(1, &VBO_TerraCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraCol);
  glBufferData(GL_ARRAY_BUFFER,sizeof(color), color, GL_STATIC_DRAW);

  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0 , 0);
  glEnableVertexAttribArray(colorLoc);

  glBindVertexArray (0);
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
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  viewLoc = glGetUniformLocation(program->programId(), "view");
  projLoc = glGetUniformLocation(program->programId(), "project");
}

