#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFont>
#include <QObject>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{



}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Up)
    {
        qDebug()<<"1"<<endl;

    }
}
