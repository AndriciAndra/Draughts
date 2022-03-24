#ifndef RANKING_H
#define RANKING_H

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
namespace Ui {
class ranking;
}

class ranking : public QDialog
{
    Q_OBJECT

public:

    explicit ranking(QWidget *parent = nullptr);
    ~ranking();
    int my_sd;
    void descriptor_copy_to_var()
        {
            this->my_sd = Connection::client_sd;
        }

private slots:
    void on_BackButton_clicked();

private:
    Ui::ranking *ui;
};

#endif // RANKING_H
