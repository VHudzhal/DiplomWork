#include "scene3d.h"
#include "ui_diplomwork.h"
#include "diplomwork.h"
#include <QtGui>
#include <QWidget>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QTextEdit>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QMenuBar>
#include <QStringList>
#include <QTextFormat>
#include <qmainwindow.h>
#include <QOpenGLFunctions>
#include <QtWidgets\qopenglwidget.h>
#include <QColor>
#include <QtOpenGL>
#include <QGLWidget>
#include "GL/gl.h"
#include "GL/glu.h"


namespace Ui {
    class DiplomWork;
}

Scene3D::Scene3D(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::DiplomWork)
{
}

void Scene3D::initializeGL()
{
        glEnable(GL_DEPTH_TEST); // устанавливаем режим проверки глубины пикселя
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
}

void Scene3D::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION); //устанавливаем текущую проекционную матрицу
    glLoadIdentity();
    GLfloat ratio=nHeight/nWidth;
    if (nWidth>=nHeight)
       glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0);
    else
       glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void Scene3D::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    xRot=-90;
    yRot=0;
    zRot=0;
    zTra=0;
    nSca=1;
    //    последовательно преобразование
    glScalef(nSca,nSca,nSca); // масштабирование
    glTranslatef(0.0f, zTra,0.0f);
    glRotatef(xRot,1.0f,0.0f,0.0);
    glRotatef(yRot,0.0f,1.0f,0.0);
    glRotatef(zRot,0.0f,0.0f,1.0);
    glLineWidth(5.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f( 0,0, 0);
    glVertex3f( 0,100,0);
    glVertex3f(100,100,0);
    glVertex3f(100,0, 0);
    glEnd();
    glLineWidth(1.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
    for(int i=0;i<=100;i++)
  { glVertex3f(i,0,0);
    glVertex3f(i,100,0);
    glVertex3f(0,i,0);
    glVertex3f(100,i,0);
  };
    glEnd();
    ui->widget;
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
   }

void Scene3D::mouseReleaseEvent(QMouseEvent* e)
{

}

void Scene3D::wheelEvent(QWheelEvent* e)
{
   if ((e->delta())>0) scale_plus();
   else
       if ((e->delta())<0) scale_minus();

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


void Scene3D::drawAxis() // построить оси координат
{
    glLineWidth(3.0f);
    glColor4f(1.00f, 0.00f, 0.00f, 1.0f); // устанавливается цвет последующих линий

        glBegin(GL_LINES); // построение линии
            glVertex3f( 1.0f,  0.0f,  0.0f); // первая точка
           glVertex3f(-1.0f,  0.0f,  0.0f); // вторая точка
        glEnd();
        glBegin(GL_LINES);
           // ось y зеленого цвета
           glVertex3f( 0.0f,  1.0f,  0.0f);
           glVertex3f( 0.0f, -1.0f,  0.0f);

           glColor3f (0.0f, 1.0f, 0.0f);
           // ось z синего цвета
           glVertex3f( 0.0f,  0.0f,  1.0f);
           glVertex3f( 0.0f,  0.0f, -1.0f);
        glEnd();
ui->centralWidget->setGeometry(QWidget::geometry());
}

void Scene3D::drawFigure()
{

}
