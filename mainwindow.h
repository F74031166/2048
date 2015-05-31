#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <QMainWindow>
#include <QApplication>
#include <QFont>
#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QtGui>
#include <QPalette>
#include <QBrush>
#include <QKeyEvent>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
/*
class Game:public QWidget
{
public:
    Game();
    void random();
    void move();
    bool check();
    void end();
    int show(int r,int c);
    int getnowpoint();
    int getpoint();
    void keyPressEvent(QKeyEvent *event);
private:
    long int point;
    int tag;
    int key;
    int nowpoint;
    bool result;
    int table[4][4];
    int testtable[4][4];
    void spin(int d);


};
*/
#endif // MAINWINDOW_H
