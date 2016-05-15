#include <QApplication>
#include <QMainWindow>
#include <QSlider>
#include "scene3d.h"
#include <QHBoxLayout>
#include <QSpinBox>
#include "diplomwork.h"

namespace Ui {
    class DiplomWork;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSpinBox* nextentry = new QSpinBox;
    nextentry->setSuffix(")");
    nextentry->setSuffix(" MB");
    QSlider* on_moverecords_sliderMoved = new QSlider(Qt::Horizontal);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(nextentry);
    layout->addWidget(on_moverecords_sliderMoved);
    QObject::connect(nextentry, SIGNAL(valueChanged(int)),
    on_moverecords_sliderMoved, SLOT(setValue(int)));
    QObject::connect(on_moverecords_sliderMoved, SIGNAL(valueChanged(int)),
    nextentry, SLOT(setValue(int)));
    nextentry->setValue(99);

    DiplomWork w;
    w.show();
    return a.exec();
}
