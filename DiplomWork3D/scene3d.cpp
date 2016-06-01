#include "scene3d.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QVector2D>
#include <QtGui>
#include "diplomwork.h"
#include <math.h>
#include <gl/glext.h>
#include <gl/gl.h>

Scene3D::Scene3D(QWidget *parent)
    : QGLWidget(parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    nSca = 1;
}

Scene3D::~Scene3D()
{
}

void Scene3D::initializeGL()
{
    qglClearColor(Qt::white);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void Scene3D::resizeGL(GLint nWidth, GLint nHeight)
{
//    int side = qMin(nWidth, nHeight);
//    glViewport((nWidth - side) / 2, (nHeight - side) / 2, side, side);
    glViewport(0, 0, nWidth, nHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void Scene3D::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);

    glScalef(nSca, nSca, nSca);
    glTranslatef(0.0f, zTra, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(zRot, 0.0f, 0.0f, 1.0f);

    drawAxis();
    drawFigure();

}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void Scene3D::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void Scene3D::drawAxis()
{
       glLineWidth(3.0f);

       glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
       // ось x
       glBegin(GL_LINES);
          glVertex3f( 1.0f,  0.0f,  0.0f);
          glVertex3f(-1.0f,  0.0f,  0.0f);
       glEnd();

       QColor halfGreen(0, 128, 0, 255);
       qglColor(halfGreen);
       glBegin(GL_LINES);
       // ось y

          glVertex3f( 0.0f,  1.0f,  0.0f);
          glVertex3f( 0.0f, -1.0f,  0.0f);

          glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
          // ось z

          glVertex3f( 0.0f,  0.0f,  1.0f);
          glVertex3f( 0.0f,  0.0f, -1.0f);
       glEnd();
}

void Scene3D::drawFigure()
{
    qglColor(Qt::red);
    glBegin(GL_QUADS);
    glNormal3f(0,0,-1);
    glVertex3f(1,-0.5,-0.5);
    glVertex3f(1,0.5,-0.5);
    glVertex3f(1,0.5,0.5);
    glVertex3f(1,-0.5,0.5);
    glEnd();

    //
    glBegin(GL_QUADS);
    qglColor(Qt::darkGray);
    glVertex3f(-1,-0.5,-0.5);
    glVertex3f(-1,-0.5,0.5);
    glVertex3f(1,-0.5,0.5);
    glVertex3f(1,-0.5,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    qglColor(Qt::black);
    glNormal3f(0,0,-1);
    glVertex3f(-1,-0.5,-0.5);
    glVertex3f(-1,0.5,-0.5);
    glVertex3f(1,0.5,-0.5);
    glVertex3f(1,-0.5,-0.5);
    glEnd();

    //top
    glBegin(GL_QUADS);
qglColor(Qt::yellow);
glNormal3f(0,0,-1);
    glVertex3f(-1,0.5,0.5);
    glVertex3f(-1,0.5,-0.5);
    glVertex3f(1,0.5,-0.5);
    glVertex3f(1,0.5,0.5);
    glEnd();


    glBegin(GL_QUADS);
    qglColor(Qt::darkGreen);
    glNormal3f(0,0,-1);
    glVertex3f(-1,-0.5,0.5);
    glVertex3f(-1,0.5,0.5);
    glVertex3f(1,0.5,0.5);
    glVertex3f(1,-0.5,0.5);
    glPointSize(5);
    glEnd();

    glBegin(GL_QUADS);
    qglColor(Qt::blue);
    glNormal3f(0,0,-1);
    glVertex3f(-1,-0.5,-0.5);
    glVertex3f(-1,-0.5,0.5);
    glVertex3f(-1,0.5,0.5);
    glVertex3f(-1,0.5,-0.5);
    glPointSize(5);
    glEnd();

}



void Scene3D::mousePressEvent(QMouseEvent* e)
{
    mousePos = e->pos();
}

void Scene3D::mouseMoveEvent(QMouseEvent* e)
{
    xRot += 180/nSca*(GLfloat)(e->y()-mousePos.y())/height();
    zRot += 180/nSca*(GLfloat)(e->x()-mousePos.x())/width();
    mousePos = e->pos();
    updateGL();
}

void Scene3D::mouseReleaseEvent(QMouseEvent* e)
{

}

void Scene3D::wheelEvent(QWheelEvent* e)
{
    if ((e->delta())>0)
        scale_plus();
    else
        if ((e->delta())<0) scale_minus();
updateGL();
}


void Scene3D::keyPressEvent(QKeyEvent* e)
{
    switch (e->key())
    {
    case Qt::Key_Plus:
        scale_plus();
        break;

    case Qt::Key_Equal:
        scale_plus();
        break;

    case Qt::Key_Minus:
        scale_minus();
        break;

    case Qt::Key_Up:
        rotate_up();
        break;

    case Qt::Key_Down:
        rotate_down();
        break;

    case Qt::Key_Left:
        rotate_left();
        break;

    case Qt::Key_Right:
        rotate_right();
        break;

    case Qt::Key_Z:
        translate_down();
        break;

    case Qt::Key_X:
        translate_up();
        break;

    case Qt::Key_Space:
        defaultScene();
        break;

    case Qt::Key_Escape:
        this->close();
        break;
    }
}

void Scene3D::scale_plus()
{
    nSca = nSca*1.1;
}

void Scene3D::scale_minus()
{
    nSca = nSca/1.1;
}

void Scene3D::rotate_up()
{
    xRot += 1.0;
}

void Scene3D::rotate_down()
{
    xRot -= 1.0;
}

void Scene3D::rotate_left()
{
    zRot += 1.0;
}

void Scene3D::rotate_right()
{
    zRot -= 1.0;
}

void Scene3D::translate_down()
{
    zTra -= 0.05;
}

void Scene3D::translate_up()
{
    zTra += 0.05;
}

void Scene3D::defaultScene()
{
    xRot=-90; yRot=0; zRot=0; zTra=0; nSca=1;
}
