#ifndef LGAMEWINDOW_H
#define LGAMEWINDOW_H

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
#include "connection.h"
#include <QVector>
#include <QLabel>
#include <vector>
#include <QMouseEvent>
namespace Ui {
class lgamewindow;
}

class lgamewindow : public QDialog
{
    Q_OBJECT

public:
    explicit lgamewindow(QWidget *parent = nullptr);
    ~lgamewindow();
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
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::lgamewindow *ui;
};

#endif // LGAMEWINDOW_H
