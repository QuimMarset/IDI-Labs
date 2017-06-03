#include "MyGLWidget.h"

#include <iostream>
using namespace std;
#include <cmath>


MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent)
{
  setFocusPolicy(Qt::ClickFocus);  // per rebre events de teclat
  scale = 1.0f;
  angleX = 0.0f;
  angleY = 0.0f;
  rav = 1.0f;
  modelSeleccionat = true;
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
  modelPatricio.load("../../Models/Patricio.obj");
  modelLegoman.load("../../Models/legoman.obj");
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

  if (modelSeleccionat) {
    //pinta Patricios

    modelTransformPatricio1 ();
    glBindVertexArray (VAO_Patricio);
    glDrawArrays(GL_TRIANGLES, 0, modelPatricio.faces().size()*3);

    modelTransformPatricio2 ();
    glBindVertexArray (VAO_Patricio);
    glDrawArrays(GL_TRIANGLES, 0, modelPatricio.faces().size()*3);

  }

  else {
    //pinta Legoman

    modelTransformLegoman1 ();
    glBindVertexArray (VAO_Legoman);
    glDrawArrays(GL_TRIANGLES, 0, modelLegoman.faces().size()*3);

    modelTransformLegoman2 ();
    glBindVertexArray (VAO_Legoman);
    glDrawArrays(GL_TRIANGLES, 0, modelLegoman.faces().size()*3);

  }

  modelTransformTerra();
  glBindVertexArray(VAO_Terra);
  glDrawArrays(GL_TRIANGLES,0,6);

  glBindVertexArray (0);
}

void MyGLWidget::modelTransformPatricio1 () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::translate(transform,glm::vec3(1,0,1));
  transform = glm::scale(transform,glm::vec3(factorEscalatPatr,factorEscalatPatr,factorEscalatPatr));
  transform = glm::translate(transform,-centreBaseCapsaModelPatr);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformPatricio2 () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::translate(transform,glm::vec3(-1,0,-1));
  transform = glm::rotate(transform,(float)-M_PI,glm::vec3(0,1,0));
  transform = glm::scale(transform,glm::vec3(factorEscalatPatr,factorEscalatPatr,factorEscalatPatr));
  transform = glm::translate(transform,-centreBaseCapsaModelPatr);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformLegoman1 () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::translate(transform,glm::vec3(1,0,1));
  transform = glm::scale(transform,glm::vec3(factorEscalatLego,factorEscalatLego,factorEscalatLego));
  transform = glm::translate(transform,-centreBaseCapsaModelLego);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformLegoman2 () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::translate(transform,glm::vec3(-1,0,-1));
  transform = glm::rotate(transform,(float)-M_PI,glm::vec3(0,1,0));
  transform = glm::scale(transform,glm::vec3(factorEscalatLego,factorEscalatLego,factorEscalatLego));
  transform = glm::translate(transform,-centreBaseCapsaModelLego);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformTerra() {
  glm::mat4 transform(1.0f);
  glUniformMatrix4fv(transLoc,1,GL_FALSE,&transform[0][0]);
}

void MyGLWidget::calculaParametresCapsaPatr() {


  float xmin,xmax,ymin,ymax,zmin,zmax;
  xmin = xmax = modelPatricio.vertices()[0];
  ymin = ymax = modelPatricio.vertices()[1];
  zmin = zmax = modelPatricio.vertices()[2];


  for (unsigned int i = 3;i < modelPatricio.vertices().size();i+= 3) {
      if (modelPatricio.vertices()[i] > xmax) xmax = modelPatricio.vertices()[i];
      else if (modelPatricio.vertices()[i] < xmin) xmin = modelPatricio.vertices()[i];

      if (modelPatricio.vertices()[i+1] > ymax) ymax = modelPatricio.vertices()[i+1];
      else if (modelPatricio.vertices()[i+1] < ymin) ymin = modelPatricio.vertices()[i+1];

      if (modelPatricio.vertices()[i+2] > zmax) zmax = modelPatricio.vertices()[i+2];
      else if (modelPatricio.vertices()[i+2] < zmin) zmin = modelPatricio.vertices()[i+2];
  }

  puntMaximCapsaModelPatr = glm::vec3(xmax,ymax,zmax);
  puntMinimCapsaModelPatr = glm::vec3(xmin,ymin,zmin);

  centreBaseCapsaModelPatr = glm::vec3((xmax+xmin)/2.0f, ymin, (zmax+zmin)/2.0f);
  centreCapsaModelPatr = glm::vec3((xmax+xmin)/2.0f, (ymax+ymin)/2.0f, (zmax+zmin)/2.0f);

  factorEscalatPatr = 1.0f/(puntMaximCapsaModelPatr.y - puntMinimCapsaModelPatr.y);

}

void MyGLWidget::calculaParametresCapsaLego() {

  float xmin,xmax,ymin,ymax,zmin,zmax;
  xmin = xmax = modelLegoman.vertices()[0];
  ymax = ymin = modelLegoman.vertices()[1];
  zmax = zmin = modelLegoman.vertices()[2];

  for (unsigned int i = 3; i < modelLegoman.vertices().size();i+= 3) {

     if (modelLegoman.vertices()[i] > xmax) xmax = modelLegoman.vertices()[i];
      else if (modelLegoman.vertices()[i] < xmin) xmin = modelLegoman.vertices()[i];

      if (modelLegoman.vertices()[i+1] > ymax) ymax = modelLegoman.vertices()[i+1];
      else if (modelLegoman.vertices()[i+1] < ymin) ymin = modelLegoman.vertices()[i+1];

      if (modelLegoman.vertices()[i+2] > zmax) zmax = modelLegoman.vertices()[i+2];
      else if (modelLegoman.vertices()[i+2] < zmin) zmin = modelLegoman.vertices()[i+2];
  }

  centreCapsaModelLego = glm::vec3((xmin + xmax)/2.0f, (ymin + ymax)/2.0f, (zmin + zmax)/2.0f);
  centreBaseCapsaModelLego = glm::vec3((xmin + xmax)/2.0f, ymin, (zmin + zmax)/2.0f);

  puntMinimCapsaModelLego = glm::vec3(xmin,ymin,zmin);
  puntMaximCapsaModelLego = glm::vec3(xmax,ymax,zmax);

  factorEscalatLego = 1.0f/(puntMaximCapsaModelLego.y - puntMinimCapsaModelPatr.y);

}

void MyGLWidget::calculaParametres() {

  calculaParametresCapsaPatr();
  calculaParametresCapsaLego();

  puntMaximCapsaEscena = glm::vec3(2.0,1.0,2.0);
  puntMinimCapsaEscena = glm::vec3(-2.0,0.0,-2.0);

  radiEsfera = sqrt(pow(puntMaximCapsaEscena.x - puntMinimCapsaEscena.x,2) + pow(puntMaximCapsaEscena.y - puntMinimCapsaEscena.y,2) 
    + pow(puntMaximCapsaEscena.z - puntMinimCapsaEscena.z,2));
  radiEsfera = radiEsfera/2.0f;


}

  



void MyGLWidget::iniCamera() {

   dist = 2*radiEsfera;

  //OBS = glm::vec3(0,0,dist);
  //VRP = glm::vec3(0,0,0);
  //UP = glm::vec3(0,1,0);

  zN = radiEsfera;
  zF = 3*radiEsfera;
  angleCamera = asin(radiEsfera/dist);
  angleZoom = angleCamera;
  /*l = -radiEsfera;
  r = radiEsfera;
  b = -radiEsfera;
  t = radiEsfera;*/
  
  rav = (float)width()/(float)height();

  projectTransform();
  viewTransform();

}


void MyGLWidget::projectTransform() {

  glm::mat4 project;
  
  if (rav >= 1.0f) {
    /*l = - rav * radiEsfera; //rav * hw = aw -> dividit per dos
    r = rav * radiEsfera;
    project = glm::ortho(l,r,b,t,zN,zF);*/
    project = glm::perspective(2*angleZoom,rav,zN,zF);
  }
  else {
    /*b = - radiEsfera/rav; //aw / rav = hw -> dividit per dos
    t = radiEsfera/rav;
    project = glm::ortho(l,r,b,t,zN,zF);*/
    float angleNou = atan(tan(angleZoom)/rav);
    project = glm::perspective(2*angleNou,rav,zN,zF);
  }
  
  glUniformMatrix4fv(projLoc,1,GL_FALSE,&project[0][0]);
}

void MyGLWidget::viewTransform() {

  //glm::mat4 view = glm::lookAt(OBS,VRP,UP);
  glm::mat4 view(1.0f);
  view = glm::translate(view,glm::vec3(0,0,-dist));
  view = glm::rotate(view,(float)(30*(M_PI/180)),glm::vec3(1,0,0));
  view = glm::rotate(view,-angleX,glm::vec3(1,0,0));
  view = glm::rotate(view,-angleY,glm::vec3(0,1,0));

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
    /*case Qt::Key_S: { // escalar a més gran
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
      break;
    }*/

    /*case Qt::Key_Z: { //Zoom in -> Fov menor
      if (angleZoom*(180.0/M_PI) > 15) {
        angleZoom -= 0.1f;
        projectTransform();
      }
      break;
    }
    case Qt::Key_X: { //Zoom out -> Fov major
      if (angleZoom*(180.0/M_PI) < 60.0) {
        angleZoom += 0.1f; 
        projectTransform();
      }
      break;
    }*/

    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::mousePressEvent(QMouseEvent* event) {

  posX = event->x();
  posY = event->y();

}

void MyGLWidget::mouseMoveEvent(QMouseEvent* event) {
  makeCurrent();

  angleY += (event->x() - posX) * M_PI/180.0f;
  angleX += (event->y() - posY) * M_PI/180.0f;
  viewTransform();

  posX = event->x();
  posY = event->y();
  update();

}

void MyGLWidget::createBuffers () 
{
  // Dades de la caseta
  // Dos VBOs, un amb posició i l'altre amb color
  glm::vec3 posicio[6] = {
	glm::vec3(-2.0, 0.0, 2.0),
	glm::vec3( 2.0, 0.0, 2.0),
	glm::vec3(-2.0, 0.0, -2.0),
	glm::vec3(-2.0, 0.0, -2.0),
	glm::vec3( 2.0, 0.0, 2.0),
  glm::vec3( 2.0, 0.0, -2.0),
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
  glGenVertexArrays(1, &VAO_Patricio);
  glBindVertexArray(VAO_Patricio);

  glGenBuffers(1, &VBO_PatricioPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatricioPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*modelPatricio.faces().size()*3*3, modelPatricio.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_PatricioCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_PatricioCol);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*modelPatricio.faces().size()*3*3, modelPatricio.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);



  glGenVertexArrays(1, &VAO_Legoman);
  glBindVertexArray(VAO_Legoman);

  glGenBuffers(1, &VBO_LegomanPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_LegomanPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*modelLegoman.faces().size()*3*3,modelLegoman.VBO_vertices(), GL_STATIC_DRAW);

  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glGenBuffers(1, &VBO_LegomanCol);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_LegomanCol);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*modelLegoman.faces().size()*3*3,modelLegoman.VBO_matdiff(), GL_STATIC_DRAW);

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

//Slots de MyGLWidget

void MyGLWidget::repAngleZoom(int angle) {
  makeCurrent();
  angleZoom = (float) angle* (M_PI/180.0);
  projectTransform();
  update();
}

void MyGLWidget::repModelPatr(bool select) {
  makeCurrent();
  if (select) modelSeleccionat = true;
  update();
}

void MyGLWidget::repModelLego(bool select) {
  makeCurrent();
  if (select) modelSeleccionat = false;
  update();
}
