#ifndef LOGINWINOW_H
#define LOGINWINOW_H
#include "connection.h"
#include "mainmenu.h"
#include <QDialog>

namespace Ui {
class loginwinow;
}

class loginwinow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwinow(QWidget *parent = nullptr);
    ~loginwinow();
    int my_sd;
    void descriptor_copy_to_var()
        {
            this->my_sd = Connection::client_sd;
        }

private slots:
    void on_LoginButton2_clicked();

private:
    Ui::loginwinow *ui;
};

#endif // LOGINWINOW_H
