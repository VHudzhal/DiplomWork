#include "diplomwork.h"
#include "ui_diplomwork.h"
#include <qmainwindow.h>
#include <qwindowdefs.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QIODevice>
#include <QTableWidget>
#include <qatomic_x86.h>


namespace Ui {
    class DiplomWork;
}

DiplomWork::DiplomWork(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::DiplomWork)

{
  QTableWidget*  CoordWidget = new QTableWidget();
    CoordWidget->setColumnCount(4);
    CoordWidget->setColumnWidth(0,200);
    CoordWidget->setColumnWidth(1,200);
    CoordWidget->setColumnWidth(2,50);
    CoordWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID")));
    CoordWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("xAxis")));
    CoordWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("yAxis")));
    CoordWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("zAxis")));
    CoordWidget->setShowGrid(true);
    CoordWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    CoordWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    CoordWidget->setColumnHidden(0, true);
ui->setupUi(this);
}

DiplomWork::~DiplomWork()
{
    delete ui;
}

void DiplomWork::on_actionExit_triggered()
{
    close();
}

bool DiplomWork::on_actionOpen_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "*.txt *.doc *.xlsx");
QFile file(fileName);
if(file.open(QIODevice::ReadOnly  | QIODevice::Text))
{
QMessageBox::warning(this, tr("Spreadsheet"),
tr("Cannot read file %1:\n%2." )
.arg(file.fileName())
.arg(file.errorString()));
return false;
QDataStream in(&file);
in.setVersion(QDataStream::Qt_4_3);
quint32 magic;
in >> magic;
if (magic != MagicNumber) {
QMessageBox::warning(this, tr("Spreadsheet"),
tr("The file is not a Spreadsheet file."));
return false;
}
quint16 row;
quint16 column;
QString str = formula(row, column);
QApplication::setOverrideCursor(Qt::WaitCursor);
while ( ! in.atEnd()) {
in >> row >> column >>str;
setFormula(row, column, str);
}
QApplication::restoreOverrideCursor();
return true;
}}

void DiplomWork::on_actionSelectObject_triggered()
{

}

void DiplomWork::on_moverecords_sliderMoved(int pos)
{

}

