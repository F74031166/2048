#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <QMainWindow>
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QtGui>
#include <QPalette>
#include <QBrush>
#include <QGridLayout>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QEvent>
#include <QSlider>
#include <QFocusEvent>
#include <QTimer>
//using namespace std;

class Game:public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *window=0);
    void random();
    void move();
    bool check();
    //void end();
    int show(int r,int c);
    int getnowpoint();
    int getpoint();
    QWidget *w;
    QLCDNumber *pointL;
    QLabel *endit;
    QLabel *gameover;
    void keyPressEvent(QKeyEvent *event);
    QPushButton *pushButton;
    QPushButton *pushButton2;
    QLabel *title;
    QLabel *score;
    void getP(int d,int r,int bc,int ac);
    QTimer *movep;
public slots:
    void reset();
    void moveslot();
    void end();
private:
    //void keyPressEvent(QKeyEvent *event);
    int point;
    int tag;
    int key;
    int nowpoint;
    bool result;
    int table[4][4];
    int testtable[4][4];
    int before[16];
    int after[16];
    void spin(int d);
    int br,bc;
    int randomr,randomc;
    QString str[15];
    QLabel *num[16];





};

#endif // GAME_H
