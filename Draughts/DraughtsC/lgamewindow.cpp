#include "lgamewindow.h"
#include "ui_lgamewindow.h"
#include "mainmenu.h"
#include <stdio.h>
#include <cstring>
#include<string.h>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <QDebug>
#include <QString>
#include <QPoint>
#include <QVector>
#include <QPixmap>
#include "lgame.h"
lgamewindow::lgamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lgamewindow)
{
    ui->setupUi(this);
    descriptor_copy_to_var();
    char msg[100];
    bzero (msg, 100);
    strcpy(msg,"losing");
    msg[strlen(msg)+1]=NULL;
    if (write (my_sd, msg, 100) == -1)
          {
              perror ("[client]Eroare la write() spre server.\n");
          }

    /* citirea raspunsului dat de server
    (apel blocant pina cind serverul raspunde) */
    if (read (my_sd, msg, 100) == -1)
          {
              perror ("[client]Eroare la read() de la server.\n");
          }

        gameOver=false;
    QPixmap PA(":/img/pionAlb.png");
    QPixmap PN(":/img/pionNegru.png");
    ui->setupUi(this);
    //rand1
    ui->label11->setText(" ");
    ui->label11->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label11->setFrameStyle(QFrame::Box);
    ui->label11->setAlignment(Qt::AlignCenter);

    ui->label12->setPixmap(PA);
    ui->label12->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label12->setFrameStyle(QFrame::Box);
    ui->label12->setAlignment(Qt::AlignCenter);

    ui->label13->setText(" ");
    ui->label13->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label13->setFrameStyle(QFrame::Box);
    ui->label13->setAlignment(Qt::AlignCenter);

    ui->label14->setPixmap(PA);
    ui->label14->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label14->setFrameStyle(QFrame::Box);
    ui->label14->setAlignment(Qt::AlignCenter);

    ui->label15->setText(" ");
    ui->label15->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label15->setFrameStyle(QFrame::Box);
    ui->label15->setAlignment(Qt::AlignCenter);

    ui->label16->setPixmap(PA);
    ui->label16->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label16->setFrameStyle(QFrame::Box);
    ui->label16->setAlignment(Qt::AlignCenter);

    ui->label17->setText(" ");
    ui->label17->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label17->setFrameStyle(QFrame::Box);
    ui->label17->setAlignment(Qt::AlignCenter);

    ui->label18->setPixmap(PA);
    ui->label18->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label18->setFrameStyle(QFrame::Box);
    ui->label18->setAlignment(Qt::AlignCenter);
    //rand2
    ui->label21->setPixmap(PA);
    ui->label21->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label21->setFrameStyle(QFrame::Box);
    ui->label21->setAlignment(Qt::AlignCenter);

    ui->label22->setText(" ");
    ui->label22->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label22->setFrameStyle(QFrame::Box);
    ui->label22->setAlignment(Qt::AlignCenter);

    ui->label23->setPixmap(PA);
    ui->label23->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label23->setFrameStyle(QFrame::Box);
    ui->label23->setAlignment(Qt::AlignCenter);

    ui->label24->setText(" ");
    ui->label24->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label24->setFrameStyle(QFrame::Box);
    ui->label24->setAlignment(Qt::AlignCenter);

    ui->label25->setPixmap(PA);
    ui->label25->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label25->setFrameStyle(QFrame::Box);
    ui->label25->setAlignment(Qt::AlignCenter);

    ui->label26->setText(" ");
    ui->label26->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label26->setFrameStyle(QFrame::Box);
    ui->label26->setAlignment(Qt::AlignCenter);

    ui->label27->setPixmap(PA);
    ui->label27->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label27->setFrameStyle(QFrame::Box);
    ui->label27->setAlignment(Qt::AlignCenter);

    ui->label28->setText(" ");
    ui->label28->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label28->setFrameStyle(QFrame::Box);
    ui->label28->setAlignment(Qt::AlignCenter);
    //rand3
    ui->label31->setText(" ");
    ui->label31->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label31->setFrameStyle(QFrame::Box);
    ui->label31->setAlignment(Qt::AlignCenter);

    ui->label32->setPixmap(PA);
    ui->label32->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label32->setFrameStyle(QFrame::Box);
    ui->label32->setAlignment(Qt::AlignCenter);

    ui->label33->setText(" ");
    ui->label33->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label33->setFrameStyle(QFrame::Box);
    ui->label33->setAlignment(Qt::AlignCenter);

    ui->label34->setPixmap(PA);
    ui->label34->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label34->setFrameStyle(QFrame::Box);
    ui->label34->setAlignment(Qt::AlignCenter);

    ui->label35->setText(" ");
    ui->label35->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label35->setFrameStyle(QFrame::Box);
    ui->label35->setAlignment(Qt::AlignCenter);

    ui->label36->setPixmap(PA);
    ui->label36->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label36->setFrameStyle(QFrame::Box);
    ui->label36->setAlignment(Qt::AlignCenter);

    ui->label37->setText(" ");
    ui->label37->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label37->setFrameStyle(QFrame::Box);
    ui->label37->setAlignment(Qt::AlignCenter);

    ui->label38->setPixmap(PA);
    ui->label38->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label38->setFrameStyle(QFrame::Box);
    ui->label38->setAlignment(Qt::AlignCenter);
    //rand4
    ui->label41->setText(" ");
    ui->label41->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label41->setFrameStyle(QFrame::Box);
    ui->label41->setAlignment(Qt::AlignCenter);

    ui->label42->setText(" ");
    ui->label42->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label42->setFrameStyle(QFrame::Box);
    ui->label42->setAlignment(Qt::AlignCenter);

    ui->label43->setText(" ");
    ui->label43->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label43->setFrameStyle(QFrame::Box);
    ui->label43->setAlignment(Qt::AlignCenter);

    ui->label44->setText(" ");
    ui->label44->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label44->setFrameStyle(QFrame::Box);
    ui->label44->setAlignment(Qt::AlignCenter);

    ui->label45->setText(" ");
    ui->label45->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label45->setFrameStyle(QFrame::Box);
    ui->label45->setAlignment(Qt::AlignCenter);

    ui->label46->setText(" ");
    ui->label46->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label46->setFrameStyle(QFrame::Box);
    ui->label46->setAlignment(Qt::AlignCenter);

    ui->label47->setText(" ");
    ui->label47->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label47->setFrameStyle(QFrame::Box);
    ui->label47->setAlignment(Qt::AlignCenter);

    ui->label48->setText(" ");
    ui->label48->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label48->setFrameStyle(QFrame::Box);
    ui->label48->setAlignment(Qt::AlignCenter);
    //rand5
    ui->label51->setText(" ");
    ui->label51->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label51->setFrameStyle(QFrame::Box);
    ui->label51->setAlignment(Qt::AlignCenter);

    ui->label52->setText(" ");
    ui->label52->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label52->setFrameStyle(QFrame::Box);
    ui->label52->setAlignment(Qt::AlignCenter);

    ui->label53->setText(" ");
    ui->label53->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label53->setFrameStyle(QFrame::Box);
    ui->label53->setAlignment(Qt::AlignCenter);

    ui->label54->setText(" ");
    ui->label54->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label54->setFrameStyle(QFrame::Box);
    ui->label54->setAlignment(Qt::AlignCenter);

    ui->label55->setText(" ");
    ui->label55->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label55->setFrameStyle(QFrame::Box);
    ui->label55->setAlignment(Qt::AlignCenter);

    ui->label56->setText(" ");
    ui->label56->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label56->setFrameStyle(QFrame::Box);
    ui->label56->setAlignment(Qt::AlignCenter);

    ui->label57->setText(" ");
    ui->label57->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label57->setFrameStyle(QFrame::Box);
    ui->label57->setAlignment(Qt::AlignCenter);

    ui->label58->setText(" ");
    ui->label58->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label58->setFrameStyle(QFrame::Box);
    ui->label58->setAlignment(Qt::AlignCenter);
    //rand6
    ui->label61->setPixmap(PN);
    ui->label61->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label61->setFrameStyle(QFrame::Box);
    ui->label61->setAlignment(Qt::AlignCenter);

    ui->label62->setText(" ");
    ui->label62->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label62->setFrameStyle(QFrame::Box);
    ui->label62->setAlignment(Qt::AlignCenter);

    ui->label63->setPixmap(PN);
    ui->label63->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label63->setFrameStyle(QFrame::Box);
    ui->label63->setAlignment(Qt::AlignCenter);

    ui->label64->setText(" ");
    ui->label64->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label64->setFrameStyle(QFrame::Box);
    ui->label64->setAlignment(Qt::AlignCenter);

    ui->label65->setPixmap(PN);
    ui->label65->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label65->setFrameStyle(QFrame::Box);
    ui->label65->setAlignment(Qt::AlignCenter);

    ui->label66->setText(" ");
    ui->label66->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label66->setFrameStyle(QFrame::Box);
    ui->label66->setAlignment(Qt::AlignCenter);

    ui->label67->setPixmap(PN);
    ui->label67->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label67->setFrameStyle(QFrame::Box);
    ui->label67->setAlignment(Qt::AlignCenter);

    ui->label68->setText(" ");
    ui->label68->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label68->setFrameStyle(QFrame::Box);
    ui->label68->setAlignment(Qt::AlignCenter);
    //rand7
    ui->label71->setText(" ");
    ui->label71->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label71->setFrameStyle(QFrame::Box);
    ui->label71->setAlignment(Qt::AlignCenter);

    ui->label72->setPixmap(PN);
    ui->label72->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label72->setFrameStyle(QFrame::Box);
    ui->label72->setAlignment(Qt::AlignCenter);

    ui->label73->setText(" ");
    ui->label73->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label73->setFrameStyle(QFrame::Box);
    ui->label73->setAlignment(Qt::AlignCenter);

    ui->label74->setPixmap(PN);
    ui->label74->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label74->setFrameStyle(QFrame::Box);
    ui->label74->setAlignment(Qt::AlignCenter);

    ui->label75->setText(" ");
    ui->label75->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label75->setFrameStyle(QFrame::Box);
    ui->label75->setAlignment(Qt::AlignCenter);

    ui->label76->setPixmap(PN);
    ui->label76->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label76->setFrameStyle(QFrame::Box);
    ui->label76->setAlignment(Qt::AlignCenter);

    ui->label77->setText(" ");
    ui->label77->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label77->setFrameStyle(QFrame::Box);
    ui->label77->setAlignment(Qt::AlignCenter);

    ui->label78->setPixmap(PN);
    ui->label78->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label78->setFrameStyle(QFrame::Box);
    ui->label78->setAlignment(Qt::AlignCenter);
    //rand8
    ui->label81->setPixmap(PN);
    ui->label81->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label81->setFrameStyle(QFrame::Box);
    ui->label81->setAlignment(Qt::AlignCenter);

    ui->label82->setText(" ");
    ui->label82->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label82->setFrameStyle(QFrame::Box);
    ui->label82->setAlignment(Qt::AlignCenter);

    ui->label83->setPixmap(PN);
    ui->label83->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label83->setFrameStyle(QFrame::Box);
    ui->label83->setAlignment(Qt::AlignCenter);

    ui->label84->setText(" ");
    ui->label84->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label84->setFrameStyle(QFrame::Box);
    ui->label84->setAlignment(Qt::AlignCenter);

    ui->label85->setPixmap(PN);
    ui->label85->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label85->setFrameStyle(QFrame::Box);
    ui->label85->setAlignment(Qt::AlignCenter);

    ui->label86->setText(" ");
    ui->label86->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label86->setFrameStyle(QFrame::Box);
    ui->label86->setAlignment(Qt::AlignCenter);

    ui->label87->setPixmap(PN);
    ui->label87->setStyleSheet("QLabel{background-color:brown;color:black}");
    ui->label87->setFrameStyle(QFrame::Box);
    ui->label87->setAlignment(Qt::AlignCenter);

    ui->label88->setText(" ");
    ui->label88->setStyleSheet("QLabel{background-color:yellow;color:black}");
    ui->label88->setFrameStyle(QFrame::Box);
    ui->label88->setAlignment(Qt::AlignCenter);
    char turn[20];
    for(int i=64;i<=strlen(msg)+1;++i)
    {
        turn[i-64]=msg[i];
    }
    turn[strlen(turn)]='\0';
    ui->labelTurn->setText(turn);

}

lgamewindow::~lgamewindow()
{
    delete ui;
}

void lgamewindow::mousePressEvent(QMouseEvent *event)
{
    if(!gameOver)
    {
    if(event->button()==Qt::LeftButton)
     {
        if (FirstClick==true)
        {
            FirstCoordx=event->x();
            FirstCoordy=event->y();
            FirstClick=false;
        }
        else
        {
            SecondCoordx=event->x();
            SecondCoordy=event->y();
            FirstClick=true;
            update();
        }
    }
    if(SecondCoordx!=-1)
        {
        char msg[100],s;
        int x1,y1,x2,y2;
        y1=FirstCoordx/83+1;
        x1=FirstCoordy/49+1;
        y2=SecondCoordx/83+1;
        x2=SecondCoordy/49+1;

        std::string tmp=std::to_string(x1);
        const char* t=tmp.c_str();
        strcpy(msg,t);
        std::string tmp1=std::to_string(y1);
        const char* t1=tmp1.c_str();
        strcat(msg,t1);
        std::string tmp2=std::to_string(x2);
        const char* t2=tmp2.c_str();
        strcat(msg,t2);
        std::string tmp3=std::to_string(y2);
        const char* t3=tmp3.c_str();
        strcat(msg,t3);
        msg[strlen(msg)+1]='\0';
        FirstCoordx=-1;
        FirstCoordy=-1;
        SecondCoordx=-1;
        SecondCoordy=-1;
        write(my_sd,msg,100);
        hide();
        lgame *nextframe;
        nextframe=new lgame(this);
        nextframe->show();
        }
    }
}



void lgamewindow::on_pushButton_clicked()
{
    char msg[100];
    strcpy(msg,"back");
    write(my_sd,msg,100);
    hide();
    MainMenu *back;
    back=new MainMenu();
    back->show();
}

