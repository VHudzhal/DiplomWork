#ifndef DIPLOMWORK_H
#define DIPLOMWORK_H
#include "scene3d.h"
#include <QMainWindow>
#include <qboxlayout.h>
#include "ui_diplomwork.h"
#include <qwindowdefs.h>
#include <QOpenGLWidget>
#include <QTableWidget>
#include <qatomic_x86.h>
namespace Ui {
    class DiplomWork;
}

class DiplomWork : public QMainWindow
{
    Q_OBJECT

public:
    explicit DiplomWork(QMainWindow *parent = 0);
    ~DiplomWork();
private slots:
    void on_actionExit_triggered();

    bool on_actionOpen_File_triggered();

    void on_actionSelectObject_triggered();

    void on_moverecords_sliderMoved(int position);

private:
    void CoordWidget();
    QString formula(int row, int column) const;
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount =26 };
    void setFormula(int row, int column, const QString &formula);
Ui::DiplomWork *ui;
};

#endif // DIPLOMWORK_H
