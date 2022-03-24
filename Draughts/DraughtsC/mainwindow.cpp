#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "secondwindow.h"
#include "thirdwindow.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    SecondWindow *LoginWindow;
    LoginWindow=new SecondWindow(this);
    LoginWindow->show();

}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    thirdwindow *signupWindow;
    signupWindow=new thirdwindow(this);
    signupWindow->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    descriptor_copy_to_var();
    char msg[100];
    strcpy(msg,"exit");
    msg[strlen(msg)+1]=NULL;
    write(my_sd,msg,100);
}

