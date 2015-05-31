#include "mainwindow.h"
#include <iostream>
#include <cstdlib>
#include "Game.h"
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

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



    QWidget *w=new QWidget;
    /*
    w->setWindowTitle("2048");
    w->resize(500,500);
    w->setObjectName("w");
    w->setStyleSheet("#w{border-image:url(:/new/prefix1/handsome.png);}");
    QPushButton *pushButton=new QPushButton("Quit",w);
    QPushButton *pushButton2=new QPushButton("Restart",w);
    pushButton->setFont(QFont("Times", 9, QFont::UnderlineResolved));
    pushButton2->setFont(QFont("Times", 9, QFont::Black));
    pushButton->setGeometry(200,60,90,30);
    pushButton2->setGeometry(200,15,90,30);
    QObject::connect(pushButton,SIGNAL(clicked()), w, SLOT(close()));
    pushButton->setFocusPolicy(Qt::ClickFocus);
    pushButton2->setFocusPolicy(Qt::ClickFocus);
    QLabel *title= new QLabel(w);
    title->setStyleSheet("border-image:url(:/new/prefix1/2048title.png);");
    title->setGeometry(50,10,120,80);
    QObject::connect(pushButton2,SIGNAL(clicked()),t,SLOT(reset()));
    */
    Game *t=new Game(w);
    t->setFocus();
    t->setFocusPolicy(Qt::TabFocus);
    //t->reset();




    //title->setObjectName("t");
    //w->setFocusPolicy(Qt::TabFocus);/////////
    //"<html><head/><body><p><img src=:/new/prefix1/2048title.png/></p></body></html>",
    //title->setFont(QFont("Terminal_HexTall",QFont::Bold));
    //title->setStyleSheet("background-color : red");
    //title->setText("<html><head/><body><p><span style=font-size:36pt; font-weight:600; text-decoration: underline; color:#55ff00;>2048</span></p></body></html>");

    //QLCDNumber *point=new QLCDNumber(w);
    //point->setGeometry(350,40,100,30);

    /*
    QString str[15];
    str[1]="border-image:url(:/new/prefix1/2.png);";
    str[2]="border-image:url(:/new/prefix1/4.png);";
    str[3]="#n{border-image:url(:/new/prefix1/8.png);}";
    str[4]="#n{border-image:url(:/new/prefix1/16.png);}";
    str[5]="#n{border-image:url(:/new/prefix1/32.png);}";
    str[6]="#n{border-image:url(:/new/prefix1/64.png);}";
    str[7]="#n{border-image:url(:/new/prefix1/128.png);}";
    str[8]="#n{border-image:url(:/new/prefix1/256.png);}";
    str[9]="#n{border-image:url(:/new/prefix1/512.png);}";
    str[10]="#n{border-image:url(:/new/prefix1/1024.png);}";
    str[11]="#n{border-image:url(:/new/prefix1/2048.png);}";
    */

    //first:   70,130
    //num->setGeometry(250,250,20,20);
    /*
    int br=95,bc=130;//,pt=150;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QLabel *num=new QLabel(w);
            //num->setObjectName("n");
            num->setStyleSheet(str[2]);
            num->setGeometry(br+j*80,bc+i*80,70,70);
        }
    }
    */
    //point.display(pt);

    //str[12]=
    //str[13]=
    //w.setFocus();
    //int tag;
    //w->setFocus();

    //t->setFocusProxy(w);

    //t->setFocusPolicy(Qt::StrongFocus);
    //w->setFocusPolicy(Qt::TabFocus);
    /*
    while(test.check()==true)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                tag=test.show(i,j);
                if(tag!=0)
                {
                QLabel *num=new QLabel(&w);
                num->setObjectName("n");
                num->setStyleSheet(str[tag]);
                num->setGeometry(br+j*80,bc+i*80,70,70);
                }
            }
        }

        point.display(test.getpoint());
        test.move();
        test.random();


    }
    */
    //if(test.check()==false)
    //    return 0;
    w->show();
    return a.exec();
}


