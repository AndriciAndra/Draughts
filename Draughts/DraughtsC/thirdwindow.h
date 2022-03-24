#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

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
namespace Ui {
class thirdwindow;
}

class thirdwindow : public QDialog
{
    Q_OBJECT

public:
    explicit thirdwindow(QWidget *parent = nullptr);
    ~thirdwindow();
    int my_sd;
    void descriptor_copy_to_var()
        {
            this->my_sd = Connection::client_sd;
        }

private slots:
    void on_pushButton_clicked();

private:
    Ui::thirdwindow *ui;
};

#endif // THIRDWINDOW_H
