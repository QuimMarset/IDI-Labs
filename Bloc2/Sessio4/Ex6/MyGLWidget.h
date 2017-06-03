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


   public slots:
    void repAngleZoom(int angle);
    void repModelPatr(bool select);
    void repModelLego(bool select);
    void repCameraPersp(bool select);
    void repCameraOrt(bool select);
    void repAngleX(int angle);
    void repAngleY(int angle);
    void repColorR(int value);
    void repColorG(int value);
    void repColorB(int value);

   signals:
    void enviaAngleX(int angle);
    void enviaAngleY(int angle);




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
    void modelTransformLegoman1();
    void modelTransformLegoman2();
    void modelTransformTerra();
    void viewTransform();
    void projectTransform();
    void calculaParametresCapsaPatr();
    void calculaParametresCapsaLego();
    void calculaParametres();
    void iniCamera();
    void carregaBuffersColorTerra();

    // attribute locations
    GLuint vertexLoc, colorLoc;
    // uniform locations
    GLuint transLoc,viewLoc,projLoc;
    // VAO i VBO names
    GLuint VAO_Patricio, VBO_PatricioPos, VBO_PatricioCol;
    GLuint VAO_Legoman, VBO_LegomanPos, VBO_LegomanCol;
    GLuint VAO_Terra, VBO_TerraPos, VBO_TerraCol;

    //float angleRotacio;
    float rav;
    float zN, zF, dist;
    float angleCamera;
    bool modelSeleccionat; //1 Patricio 0 Legoman
    bool cameraSeleccionada; //1 perspectiva 0 ortogonal
    glm::vec3 OBS,VRP,UP;
    float radiEsfera;
    glm::vec3 puntMinimCapsaEscena,puntMaximCapsaEscena, puntMaximCapsaModelPatr, puntMinimCapsaModelPatr;
    glm::vec3 centreCapsaModelPatr, centreBaseCapsaModelPatr;
    glm::vec3 puntMaximCapsaModelLego, puntMinimCapsaModelLego, centreCapsaModelLego, centreBaseCapsaModelLego;

    float angleX, angleY;
    int posX,posY;
    float angleZoom;
    float factorEscalatPatr,factorEscalatLego;

    float colorR, colorG, colorB;

    Model modelPatricio, modelLegoman;
    // Program
    QOpenGLShaderProgram *program;
    // Internal vars
    float scale;
    glm::vec3 pos;
};

