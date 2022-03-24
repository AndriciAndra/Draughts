#include "ranking.h"
#include "ui_ranking.h"
#include "mainmenu.h"
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
ranking::ranking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ranking)
{
    ui->setupUi(this);

    descriptor_copy_to_var();
    char msg[100];
    bzero (msg, 100);
    strcpy(msg,"clasament");
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
    std::vector<std::string> ranking;
    char *p;

    p=strtok(msg,".");
    while(p!=NULL)
    {
        char nume[20];
        strcpy(nume,p);
        nume[strlen(nume)]='\0';
        ranking.push_back(nume);
        p=strtok(NULL,".");

    }
    int i=0;

    ui->no1->setTextFormat(Qt::PlainText);
    ui->no1->setText(ranking[i].c_str());
    i+=2;

    ui->no2->setTextFormat(Qt::PlainText);
    ui->no2->setText(ranking[i].c_str());
    i+=2;

    ui->no3->setTextFormat(Qt::PlainText);
    ui->no3->setText(ranking[i].c_str());
    i+=2;

    ui->no4->setTextFormat(Qt::PlainText);
    ui->no4->setText(ranking[i].c_str());
    i+=2;

    ui->no5->setTextFormat(Qt::PlainText);
    ui->no5->setText(ranking[i].c_str());
    i+=2;

    ui->no6->setTextFormat(Qt::PlainText);
    ui->no6->setText(ranking[i].c_str());
    i+=2;

    ui->no7->setTextFormat(Qt::PlainText);
    ui->no7->setText(ranking[i].c_str());
    i+=2;

    ui->no8->setTextFormat(Qt::PlainText);
    ui->no8->setText(ranking[i].c_str());
    i+=2;

    ui->no9->setTextFormat(Qt::PlainText);
    ui->no9->setText(ranking[i].c_str());
    i+=2;

    ui->no10->setTextFormat(Qt::PlainText);
    ui->no10->setText(ranking[i].c_str());
    i=1;

    ui->s1->setTextFormat(Qt::PlainText);
    ui->s1->setText(ranking[i].c_str());
    i+=2;

    ui->s2->setTextFormat(Qt::PlainText);
    ui->s2->setText(ranking[i].c_str());
    i+=2;

    ui->s3->setTextFormat(Qt::PlainText);
    ui->s3->setText(ranking[i].c_str());
    i+=2;

    ui->s4->setTextFormat(Qt::PlainText);
    ui->s4->setText(ranking[i].c_str());
    i+=2;

    ui->s5->setTextFormat(Qt::PlainText);
    ui->s5->setText(ranking[i].c_str());
    i+=2;

    ui->s6->setTextFormat(Qt::PlainText);
    ui->s6->setText(ranking[i].c_str());
    i+=2;

    ui->s7->setTextFormat(Qt::PlainText);
    ui->s7->setText(ranking[i].c_str());
    i+=2;

    ui->s8->setTextFormat(Qt::PlainText);
    ui->s8->setText(ranking[i].c_str());
    i+=2;

    ui->s9->setTextFormat(Qt::PlainText);
    ui->s9->setText(ranking[i].c_str());
    i+=2;

    ui->s10->setTextFormat(Qt::PlainText);
    ui->s10->setText(ranking[i].c_str());
}

ranking::~ranking()
{
    delete ui;
}

void ranking::on_BackButton_clicked()
{
    hide();
    MainMenu *back;
    back=new MainMenu(this);
    back->show();
}

