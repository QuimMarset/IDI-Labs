#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include "glm/glm.hpp"
#define GLM_FORCE_RADIANS

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();
    
  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ();

    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ();
 
    // resize - Es cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);  
    
    virtual void keyPressEvent (QKeyEvent *e);
    
    virtual void mouseMoveEvent ( QMouseEvent * e );
    virtual void mousePressEvent(QMouseEvent* e);
    

  private:
    void createBuffers ();
    void carregaShaders ();
    void modelTransform();
  
    
    // attribute locations
    GLuint vertexLoc;
    GLfloat tx,ty;
    GLint transLoc,colorLoc;
    GLfloat factorX,factorY;
    int xAnt,yAnt;
    
    // Program
    QOpenGLShaderProgram *program;

    GLuint VAO, VBO[2];
};
