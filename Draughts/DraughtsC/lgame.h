#ifndef LGAME_H
#define LGAME_H
#include "connection.h"
#include <QDialog>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <QVector>
#include <QLabel>
#include <vector>
#include <QMouseEvent>


namespace Ui {
class lgame;
}

class lgame : public QDialog
{
    Q_OBJECT

public:
    explicit lgame(QWidget *parent = nullptr);
    ~lgame();
    int my_sd;
    int FirstCoordx=-1;
    int FirstCoordy=-1;
    int SecondCoordx=-1;
    int SecondCoordy=-1;
    bool FirstClick=true;
    bool gameOver=false;
    void descriptor_copy_to_var()
        {
            this->my_sd = Connection::client_sd;
        }
    void readData();
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::lgame *ui;
};

#endif // LGAME_H
