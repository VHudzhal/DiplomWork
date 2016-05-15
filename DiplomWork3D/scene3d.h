#ifndef SCENE3D
#define SCENE3D
#include <QDialog>
#include <QString>
#include "math.h"
#include "diplomwork.h"
#include "ui_diplomwork.h"
#include <QOpenGLFunctions>
#include <QSlider>
#include <QtOpenGL/QGLWidget>
#include <QColor>
#include <QtOpenGL/qgl.h>
#include <QGLWidget>

class QSlider;
class QCheckBox;
class QLineEdit;
class QLabel;
class QSpinBox;
class QMenuBar;
class QMenu;
class QWidget;
class QGraphicsScene;
class Scene3D : public QWidget
{
    Q_OBJECT

public:
    explicit Scene3D(QWidget* parent = 0);
    QWidget updateGL();

private slots:


protected:

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void keyPressEvent(QKeyEvent* e);
    void wheelEvent(QWheelEvent* e);
    Ui::DiplomWork *ui;
private:
    QPoint mousePos;
    float xRot, yRot, zRot; // переменные углов поворта
    float nSca; //переменная отвечающая за масштаб объекта
    float zTra; // величина трансляции оси Z
    void scale_plus();
    void scale_minus();
    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();
    void translate_down();
    void translate_up();
    void defaultScene();
    void drawAxis();       // построить оси координат
    void drawFigure();
//    void getVertexArray();
//    void getColorArray();
//    void getIndexArray();
    void qglClearColor(Qt::GlobalColor);
    float VertexArray[12][3];
    float ColorArray[12][3];
signals:

};
#endif // SCENE3D
