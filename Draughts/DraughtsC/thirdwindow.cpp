#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "secondwindow.h"
#include <string>
#include <QMessageBox>

thirdwindow::thirdwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdwindow)
{
    ui->setupUi(this);
}

thirdwindow::~thirdwindow()
{
    delete ui;
}

void thirdwindow::on_pushButton_clicked()
{
    QString username=ui->lineUsernameSignup->text();
    std::string s=username.toStdString();
    const char* USERsignup=s.c_str();

    descriptor_copy_to_var();
    char msg[100];
    bzero (msg, 100);
    strcpy(msg,"sign up:");
    strcat(msg,USERsignup);
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
    if(strcmp(msg,"You have successfully registered! Please log in with your new username!")==0)
    {
        QMessageBox::information(this,"Sign Up",msg);
        hide();
        SecondWindow *LoginWindow;
        LoginWindow=new SecondWindow(this);
        LoginWindow->show();
    }
    else
        QMessageBox::information(this,"Sign Up",msg);
}

