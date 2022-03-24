#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include "connection.h"
#include "mainmenu.h"
#include "loginwinow.h"
#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    int my_sd;
    void descriptor_copy_to_var()
        {
            this->my_sd = Connection::client_sd;
        }

private slots:
    void on_LoginButton2_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
