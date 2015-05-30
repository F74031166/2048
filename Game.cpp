#include "Game.h"
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
#include <QGraphicsItem>
#include <QEvent>
#include <QSlider>
#include <QDebug>
#include <QFocusEvent>
#include <QTimer>

//using namespace std;


        Game::Game(QWidget *window):QWidget(window)
        {
            w=window;
            tag=0;
            key=0;
            point=0;
            nowpoint=0;
            result=false;
            int p1,p2,p3,p4;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    table[i][j]=0;
                    after[i*4+j]=i*4+j;
                    before[i*4+j]=i*4+j;
                }
            }
            srand((int)time(NULL));
            do
            {
                p1=rand()%4;
                p2=rand()%4;
                p3=rand()%4;
                p4=rand()%4;
            }while(p1==p3&&p2==p4);
            table[p1][p2]=1024;
            table[p3][p4]=1024;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    testtable[i][j]=table[i][j];
                }
            }
            /*
            w->setWindowTitle("2048");
            w->resize(500,500);
            w->setObjectName("w");
            w->setStyleSheet("#w{border-image:url(:/new/prefix1/handsome.png);}");
            pushButton=new QPushButton("Quit",w);
            pushButton2=new QPushButton("Restart",w);
            pushButton->setGeometry(200,60,90,30);
            pushButton2->setGeometry(200,15,90,30);
            QObject::connect(pushButton,SIGNAL(clicked()), w, SLOT(close()));
            title= new QLabel(w);
            title->setObjectName("t");
            title->setStyleSheet("#t{border-image:url(:/new/prefix1/2048title.png);}");
            title->setGeometry(50,10,120,80);
            pointL=new QLCDNumber(w);
            pointL->setGeometry(350,40,100,30);
            */
            str[1]="border-image:url(:/new/prefix1/2.png);";
            str[2]="border-image:url(:/new/prefix1/4.png);";
            str[3]="border-image:url(:/new/prefix1/8.png);";
            str[4]="border-image:url(:/new/prefix1/16.png);";
            str[5]="border-image:url(:/new/prefix1/32.png);";
            str[6]="border-image:url(:/new/prefix1/64.png);";
            str[7]="border-image:url(:/new/prefix1/128.png);";
            str[8]="border-image:url(:/new/prefix1/256.png);";
            str[9]="border-image:url(:/new/prefix1/512.png);";
            str[10]="border-image:url(:/new/prefix1/1024.png);";
            str[11]="border-image:url(:/new/prefix1/2048.png);";
            br=95,bc=130;
            //qDebug()<<"c"<<endl;
            //w=new QWidget;
            window->setWindowTitle("2048");
            window->resize(500,500);
            window->setObjectName("w");
            window->setStyleSheet("#w{border-image:url(:/new/prefix1/handsome.png);}");
            pushButton=new QPushButton("算了我沒屌",window);
            pushButton2=new QPushButton("不夠屌再來",window);
            pushButton->setFont(QFont("Times", 10, QFont::Bold));
            pushButton2->setFont(QFont("Times", 10, QFont::Bold));
            pushButton->setStyleSheet("border-image:url(:/new/prefix1/backgroung.png);");
            pushButton2->setStyleSheet("border-image:url(:/new/prefix1/backgroung.png);");
            pushButton->setGeometry(200,60,90,30);
            pushButton2->setGeometry(200,15,90,30);
            QObject::connect(pushButton,SIGNAL(clicked()), window, SLOT(close()));
            pushButton->setFocusPolicy(Qt::ClickFocus);
            pushButton2->setFocusPolicy(Qt::ClickFocus);
            title= new QLabel(window);
            title->setStyleSheet("border-image:url(:/new/prefix1/2048title.png);");
            title->setGeometry(50,10,120,80);
            score=new QLabel(window);
            score->setStyleSheet("border-image:url(:/new/prefix1/score.png);");
            score->setGeometry(330,10,150,50);
            //pushButton2->isDefault();
            QObject::connect(pushButton2,SIGNAL(clicked()),this,SLOT(reset()));
            movep=new QTimer;
            QObject::connect(movep,SIGNAL(timeout()),this,SLOT(moveslot()));
            for(int i=0;i<16;i++)
                num[i]=new QLabel(window);
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    tag=show(i,j);
                    if(tag!=0)
                    {
                        //num[i*4+j]=new QLabel(test);
                        //num->setObjectName("n");
                        num[i*4+j]->setStyleSheet(str[tag]);
                        num[i*4+j]->setGeometry(br+j*80,bc+i*80,70,70);
                        num[i*4+j]->show();
                    }
                    else
                    {
                        //num[i*4+j]=new QLabel(test);
                        //num->setObjectName("n");
                        num[i*4+j]->setStyleSheet(str[tag]);
                        num[i*4+j]->setGeometry(br+j*80,bc+i*80,70,70);
                        num[i*4+j]->hide();
                    }
                }
            }
            endit= new QLabel(window);
            endit->setStyleSheet("border-image:url(:/new/prefix1/great.jpg);");
            endit->setGeometry(0,0,500,500);
            endit->hide();
            gameover = new QLabel(window);
            gameover->setStyleSheet("border-image:url(:/new/prefix1/dick.png);");
            gameover->setGeometry(0,0,500,500);
            gameover->hide();
            pointL=new QLCDNumber(window);
            pointL->setGeometry(350,60,100,30);
            pointL->display(point);
            //test->setFocus();
            //window->show();
        }
        void Game::reset()
        {
            tag=0;
            key=0;
            point=0;
            nowpoint=0;
            result=false;
            int p1,p2,p3,p4;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    table[i][j]=0;

                }
            }
            srand((int)time(NULL));
            do
            {
                p1=rand()%4;
                p2=rand()%4;
                p3=rand()%4;
                p4=rand()%4;
            }while(p1==p3&&p2==p4);
            table[p1][p2]=2;
            table[p3][p4]=2;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    testtable[i][j]=table[i][j];
                }
            }
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    tag=show(i,j);
                    if(tag!=0)
                    {
                        //num[i*4+j]=new QLabel(test);
                        //num->setObjectName("n");
                        num[i*4+j]->setStyleSheet(str[tag]);
                        num[i*4+j]->setGeometry(br+j*80,bc+i*80,70,70);
                        num[i*4+j]->show();
                    }
                    else
                    {
                        //num[i*4+j]=new QLabel(test);
                        //num->setObjectName("n");
                        num[i*4+j]->setStyleSheet(str[tag]);
                        num[i*4+j]->setGeometry(br+j*80,bc+i*80,70,70);
                        num[i*4+j]->hide();
                    }
                }
            }
            pointL->display(point);
            pushButton->setGeometry(200,60,90,30);
            pushButton2->setGeometry(200,15,90,30);
            endit->hide();
            gameover->hide();
            movep=new QTimer;
            QObject::connect(movep,SIGNAL(timeout()),this,SLOT(moveslot()));
            //movep->stop();
            //window->show();
        }
        void Game::random()
        {
            int count1=0,count2=0;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(table[i][j]==testtable[i][j])
                        count1++;
                    if(table[i][j]!=0)
                        count2++;
                }
            }
            if(count1==16||count2==16)
            {
                return;
            }
            srand((int)time(NULL));
            int position_r,position_c;
            do
            {
                position_r=rand()%4;
                position_c=rand()%4;
            }while(table[position_r][position_c]!=0);
            table[position_r][position_c]=2;

            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    testtable[i][j]=table[i][j];
                }
            }
        }
        void Game::move()
        {
            int after2[4][2];
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<2;j++)
                {
                    after2[i][j]=0;
                }
            }
            for(int i=0;i<16;i++)
            {
                    before[i]=i;
                    after[i]=i;
            }
            int flag=0;
            nowpoint=0;
            if(1)
            {
                spin(key);
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        if(table[i][j]==0)
                            continue;
                        flag=j;
                        do
                        {
                            flag++;
                        }while(table[i][flag]==0&&flag<4);
                        if(flag==4)
                            break;
                        if(table[i][j]==table[i][flag])
                        {
                            table[i][j]=table[i][j]+table[i][flag];
                            getP(key,i,flag,j);
                            after2[i][0]=j;
                            after2[i][1]=flag;
                            nowpoint+=table[i][j];
                            table[i][flag]=0;
                            j++;
                        }
                    }
                }
                flag=0;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        flag=j;
                        while(table[i][flag]==0&&flag<4)
                            flag++;
                        if(flag==4)
                            break;
                        if(j!=flag)
                        {
                            table[i][j]=table[i][flag];
                            getP(key,i,flag,j);
                            if(after2[i][0]==flag)
                                getP(key,i,after2[i][1],j);
                            table[i][flag]=0;
                        }
                    }
                }
                spin(key);
                point+=nowpoint;
            }
        }
        int Game::getnowpoint()
        {
            return nowpoint;
        }
        int Game::getpoint()
        {
            return point;
        }
        int Game::show(int r,int c)
        {
            int value=table[r][c];
            int count=0;
            if(value==0)
                return value;
            else
            {
                while(value!=1)
                {
                    value/=2;
                    count++;
                }

            }
                return count;
            /*
            cout<<"point:  "<<point<<endl<<endl;//輸出
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {

                    //cout<<setw(5)<<table[i][j];//輸出改成Qlabel
                }
                //cout<<endl;
            }
            */
        }
        bool Game::check()
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(table[i][j]==2048)
                    {
                        result=true;
                        return false;
                    }
                }
            }
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(table[i][j]==0)
                        return true;
                }
            }
            bool spincheck=false;
            for(int s=0;s<4;s++)
            {
                spin(s);
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(table[i][j]==table[i][j+1])
                            spincheck=true;
                    }

                }
                spin(s);
            }
            if(spincheck==true)
                return true;
            else
                return false;
        }
        void Game::end()
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    table[i][j]=0;
                    after[i*4+j]=i*4+j;
                    before[i*4+j]=i*4+j;
                }
            }
            if(result==true)
            {

                pushButton2->setGeometry(200,200,100,30);
                pushButton->setGeometry(200,250,100,30);              
                pushButton2->raise();
                pushButton->raise();
                score->raise();
                endit->show();
                movep->stop();
            }
            else
            {

                pushButton2->setGeometry(200,200,100,30);
                pushButton->setGeometry(200,250,100,30);\
                pushButton2->raise();
                pushButton->raise();
                score->raise();
                gameover->show();
                movep->stop();

            }

        }
        void Game::spin(int d)
        {
            int temp;
            if(d==0)
                return;
            if(d==1)
            {
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3-i;j++)
                    {
                        temp=table[i][j];
                        table[i][j]=table[3-j][3-i];
                        table[3-j][3-i]=temp;
                    }
                }
            }
            if(d==2)
            {
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<2;j++)
                    {
                        temp=table[i][j];
                        table[i][j]=table[i][3-j];
                        table[i][3-j]=temp;
                    }
                }
            }
            if(d==3)
            {
                for(int i=0;i<4;i++)
                {
                    for(int j=i+1;j<4;j++)
                    {
                        temp=table[i][j];
                        table[i][j]=table[j][i];
                        table[j][i]=temp;
                    }
                }

            }

            return;
        }
        void Game::getP(int d,int r,int bc,int ac)
        {
            if(d==0)
            {
                after[r*4+bc]=r*4+ac;
            }
            else if(d==1)
            {
                after[(3-bc)*4+(3-r)]=(3-ac)*4+(3-r);
            }
            else if(d==2)
            {
                after[r*4+(3-bc)]=r*4+(3-ac);
            }
            else if(d==3)
            {
                after[bc*4+r]=ac*4+r;
            }

        }


        void Game::keyPressEvent(QKeyEvent *event)
        {
            if(movep->isActive()==true)
                return;
            if(event->key()==Qt::Key_Up)
            {
                key=3;
            }
            else if(event->key()==Qt::Key_Down)
            {
                key=1;
            }
            else if(event->key()==Qt::Key_Left)
            {
                key=0;
            }
            else if(event->key()==Qt::Key_Right)
            {
                key=2;
            }
            else
                return;            
            move();
            random();           
            movep->start(3);           
        }

        void Game::moveslot()
        {
            if(key==0)
            {
                for(int i=0;i<16;i++)
                {
                    if(after[i]!=i)
                    {

                        //qDebug()<<"move"<<endl;
                        int x=num[i]->pos().x();
                        int y=num[i]->pos().y();
                        num[i]->move(QPoint(x-4,y));
                        if(num[i]->pos().x()==(br+(after[i]%4)*80))
                        {
                            after[i]=before[i];
                        }
                    }
                }
                /*
                if(randomr!=-1&&randomc!=-1)
                {
                    int rx=num[randomr*4+randomc]->pos().x();
                    int ry=num[randomr*4+randomc]->pos().y();
                    int rh=num[randomr*4+randomc]->height();
                    int rw=num[randomr*4+randomc]->width();
                    num[randomr*4+randomc]->setGeometry(rx-4,ry-4,rw+7,rh+7);
                }
                */
            }
            else if(key==1)
            {
                for(int i=0;i<16;i++)
                {
                    if(after[i]!=i)
                    {

                        //qDebug()<<"move"<<endl;
                        int x=num[i]->pos().x();
                        int y=num[i]->pos().y();
                        num[i]->move(QPoint(x,y+4));
                        if(num[i]->pos().y()==(bc+(after[i]/4)*80))
                        {
                            after[i]=before[i];
                        }
                    }
                }
                /*
                if(randomr!=-1&&randomc!=-1)
                {
                    int rx=num[randomr*4+randomc]->pos().x();
                    int ry=num[randomr*4+randomc]->pos().y();
                    int rh=num[randomr*4+randomc]->height();
                    int rw=num[randomr*4+randomc]->width();
                    num[randomr*4+randomc]->setGeometry(rx-4,ry-4,rw+7,rh+7);
                }
                */
            }
            else if(key==2)
            {
                for(int i=0;i<16;i++)
                {
                    if(after[i]!=i)
                    {

                        //qDebug()<<"move"<<endl;
                        int x=num[i]->pos().x();
                        int y=num[i]->pos().y();
                        num[i]->move(QPoint(x+4,y));
                        if(num[i]->pos().x()==(br+(after[i]%4)*80))
                        {
                            after[i]=before[i];
                        }
                    }
                }
                /*
                if(randomr!=-1&&randomc!=-1)
                {
                    int rx=num[randomr*4+randomc]->pos().x();
                    int ry=num[randomr*4+randomc]->pos().y();
                    int rh=num[randomr*4+randomc]->height();
                    int rw=num[randomr*4+randomc]->width();
                    num[randomr*4+randomc]->setGeometry(rx-4,ry-4,rw+7,rh+7);
                }
                */
            }
            else if(key==3)
            {
                for(int i=0;i<16;i++)
                {
                    if(after[i]!=i)
                    {

                        //qDebug()<<"move"<<endl;
                        int x=num[i]->pos().x();
                        int y=num[i]->pos().y();
                        num[i]->move(QPoint(x,y-4));
                        if(num[i]->pos().y()==(bc+(after[i]/4)*80))
                        {
                            after[i]=before[i];
                        }
                    }
                }
                /*
                if(randomr!=-1&&randomc!=-1)
                {
                    int rx=num[randomr*4+randomc]->pos().x();
                    int ry=num[randomr*4+randomc]->pos().y();
                    int rh=num[randomr*4+randomc]->height();
                    int rw=num[randomr*4+randomc]->width();
                    num[randomr*4+randomc]->setGeometry(rx-4,ry-4,rw+7,rh+7);
                }
                */
            }
            int flag=0;
            for(int i=0;i<16;i++)
            {
                if(after[i]!=i)
                    flag++;
            }
            if(flag==0)
            {
                //qDebug()<<"move"<<endl;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        tag=show(i,j);
                        if(tag!=0)
                        {
                            //num[i*4+j]=new QLabel(test);
                            //num->setObjectName("n");
                            num[i*4+j]->setStyleSheet(str[tag]);
                            num[i*4+j]->setGeometry(br+j*80,bc+i*80,70,70);
                            num[i*4+j]->show();
                        }
                        else
                        {
                            //num[i*4+j]=new QLabel(test);
                            //num->setObjectName("n");
                            num[i*4+j]->setStyleSheet(str[tag]);
                            num[i*4+j]->setGeometry(br+j*80,bc+i*80,70,70);
                            num[i*4+j]->hide();
                        }
                    }
                }
                pointL->display(point);
                movep->stop();
                if(check()==false)
                {
                    QObject::connect(movep,SIGNAL(timeout()),this,SLOT(end()));
                    movep->start(1000);
                    //end();
                    //qDebug()<<"problem"<<endl;
                }
                //qDebug()<<"stop!!"<<endl;
            }
        }


