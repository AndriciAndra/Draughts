#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include "ranking.h"
#include <QMessageBox>
#include "gamewindow.h"
#include "lgamewindow.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_Logout_clicked()
{
    descriptor_copy_to_var();
    char msg[100];
    bzero (msg, 100);
    strcpy(msg,"logout");
    msg[strlen(msg)+1]='\0';
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

    QMessageBox::information(this,"Logout",msg);
    MainWindow *goback;
    goback=new MainWindow(this);
    hide();
    goback->show();
}

void MainMenu::on_Ranking_clicked()
{
    hide();
    ranking *rankingList;
    rankingList=new ranking(this);
    rankingList->show();
}

void MainMenu::on_exit_clicked()
{
    descriptor_copy_to_var();
    char msg[100];
    strcpy(msg,"exit");
    msg[strlen(msg)+1]='\0';
    write(my_sd,msg,100);
}


void MainMenu::on_ClasicDraughts_clicked()
{
    hide();
    gamewindow *game;
    game=new gamewindow(this);
    game->show();
}


void MainMenu::on_LosingDraughts_clicked()
{
    hide();
    lgamewindow *game;
    game=new lgamewindow();
    game->show();
}

