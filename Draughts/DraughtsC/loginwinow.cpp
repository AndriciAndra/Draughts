#include "loginwinow.h"
#include "ui_loginwinow.h"
#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>
#include <string>
#include <iostream>
#include <string.h>
#include "mainmenu.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include "connection.h"

loginwinow::loginwinow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginwinow)
{
    ui->setupUi(this);
}

loginwinow::~loginwinow()
{
    delete ui;
}

void loginwinow::on_LoginButton2_clicked()
{
    QString username=ui->lineUsername->text();
    std::string s=username.toStdString();
    const char* USER=s.c_str();

    descriptor_copy_to_var();
    char msg[100];
    bzero (msg, 100);
    strcpy(msg,"login:");
    strcat(msg,USER);
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
    if(strcmp(msg,"You are connected!")==0)
    {
        QMessageBox::information(this,"Login",msg);
        hide();
        MainMenu *menuprincipal;
        menuprincipal=new MainMenu(this);
        menuprincipal->show();
    }
    else
        QMessageBox::information(this,"Login",msg);
}

