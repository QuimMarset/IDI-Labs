#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "model.h"
#include <QMouseEvent>

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core 
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

  private:
    void createBuffers ();
    void carregaShaders ();
    void modelTransformPatricio1();
    void modelTransformPatricio2();
    void modelTransformTerra();
    void viewTransform();
    void projectTransform();
    void calculaParametres();
    void iniCamera();

    // attribute locations
    GLuint vertexLoc, colorLoc;
    // uniform locations
    GLuint transLoc,viewLoc,projLoc;
    // VAO i VBO names
    GLuint VAO_Patricio, VBO_PatricioPos, VBO_PatricioCol;
    GLuint VAO_Terra, VBO_TerraPos, VBO_TerraCol;

    float angleRotacio;
    float rav;
    float zN, zF, dist;
    
    glm::vec3 OBS,VRP,UP;
    float radiEsfera;
    glm::vec3 puntMinimCapsaEscena,puntMaximCapsaEscena, puntMaximCapsaModel, puntMinimCapsaModel;
    glm::vec3 centreCapsaModel, centreBaseCapsaModel;

    float angleX, angleY;
    int posX,posY;
    float angleZoom;
    float factorEscalat;

    Model model;
    // Program
    QOpenGLShaderProgram *program;
    // Internal vars
    float scale;
    glm::vec3 pos;
};

