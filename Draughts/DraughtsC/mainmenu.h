#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
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
#include "loginwinow.h"
namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    int my_sd;
    void descriptor_copy_to_var()
        {
            this->my_sd = Connection::client_sd;
        }

private slots:
    void on_Logout_clicked();

    void on_Ranking_clicked();

    void on_exit_clicked();

    void on_ClasicDraughts_clicked();

    void on_LosingDraughts_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
