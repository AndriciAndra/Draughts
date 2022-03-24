#include "lgame.h"
#include "ui_lgame.h"
#include <QMessageBox>
#include "mainmenu.h"
lgame::lgame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lgame)
{
    ui->setupUi(this);
    this->readData();
}

lgame::~lgame()
{
    delete ui;
}

void lgame::readData()
{
    descriptor_copy_to_var();
    char msg[100];
    /* citirea raspunsului dat de server
    (apel blocant pina cind serverul raspunde) */
    if (read (my_sd, msg, 100) == -1)
          {
              perror ("[client]Eroare la read() de la server.\n");
          }
    //qDebug()<<msg;
    char winmsg[100];
    strcpy(winmsg,msg);
    QPixmap PA(":/img/pionAlb.png");
    QPixmap PN(":/img/pionNegru.png");
    QPixmap DA(":/img/damaAlba.png");
    QPixmap DN(":/img/damaNeagra.png");
    if(strlen(msg)>25)
    {
        int i=0;
        ui->label11->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label11->setPixmap(PA); ui->label11->setFrameStyle(QFrame::Box);ui->label11->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label11->setPixmap(PN);ui->label11->setFrameStyle(QFrame::Box);ui->label11->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label11->setPixmap(DA);ui->label11->setFrameStyle(QFrame::Box);ui->label11->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label11->setPixmap(DN);ui->label11->setFrameStyle(QFrame::Box);ui->label11->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label11->setText(" ");ui->label11->setFrameStyle(QFrame::Box);ui->label11->setAlignment(Qt::AlignCenter);} i++;
        ui->label12->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label12->setPixmap(PA);ui->label12->setFrameStyle(QFrame::Box);ui->label12->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label12->setPixmap(PN);ui->label12->setFrameStyle(QFrame::Box);ui->label12->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label12->setPixmap(DA);ui->label12->setFrameStyle(QFrame::Box);ui->label12->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label12->setPixmap(DN);ui->label12->setFrameStyle(QFrame::Box);ui->label12->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label12->setText(" ");ui->label12->setFrameStyle(QFrame::Box);ui->label12->setAlignment(Qt::AlignCenter);} i++;

        ui->label13->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label13->setPixmap(PA);ui->label13->setFrameStyle(QFrame::Box);ui->label13->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label13->setPixmap(PN);ui->label13->setFrameStyle(QFrame::Box);ui->label13->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label13->setPixmap(DA);ui->label13->setFrameStyle(QFrame::Box);ui->label13->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label13->setPixmap(DN);ui->label13->setFrameStyle(QFrame::Box);ui->label13->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label13->setText(" ");ui->label13->setFrameStyle(QFrame::Box);ui->label13->setAlignment(Qt::AlignCenter);} i++;

            ui->label14->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label14->setPixmap(PA);ui->label14->setFrameStyle(QFrame::Box);ui->label14->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label14->setPixmap(PN);ui->label14->setFrameStyle(QFrame::Box);ui->label14->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label14->setPixmap(DA);ui->label14->setFrameStyle(QFrame::Box);ui->label14->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label14->setPixmap(DN);ui->label14->setFrameStyle(QFrame::Box);ui->label14->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label14->setText(" ");ui->label14->setFrameStyle(QFrame::Box);ui->label14->setAlignment(Qt::AlignCenter);} i++;

            ui->label15->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label15->setPixmap(PA);ui->label15->setFrameStyle(QFrame::Box);ui->label15->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label15->setPixmap(PN);ui->label15->setFrameStyle(QFrame::Box);ui->label15->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label15->setPixmap(DA);ui->label15->setFrameStyle(QFrame::Box);ui->label15->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label15->setPixmap(DN);ui->label15->setFrameStyle(QFrame::Box);ui->label15->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label15->setText(" ");ui->label15->setFrameStyle(QFrame::Box);ui->label15->setAlignment(Qt::AlignCenter);} i++;

            ui->label16->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label16->setPixmap(PA);ui->label16->setFrameStyle(QFrame::Box);ui->label16->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label16->setPixmap(PN);ui->label16->setFrameStyle(QFrame::Box);ui->label16->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label16->setPixmap(DA);ui->label16->setFrameStyle(QFrame::Box);ui->label16->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label16->setPixmap(DN);ui->label16->setFrameStyle(QFrame::Box);ui->label16->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label16->setText(" ");ui->label16->setFrameStyle(QFrame::Box);ui->label16->setAlignment(Qt::AlignCenter);} i++;

            ui->label17->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label17->setPixmap(PA);ui->label17->setFrameStyle(QFrame::Box);ui->label17->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label17->setPixmap(PN);ui->label17->setFrameStyle(QFrame::Box);ui->label17->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label17->setPixmap(DA);ui->label17->setFrameStyle(QFrame::Box);ui->label17->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label17->setPixmap(DN);ui->label17->setFrameStyle(QFrame::Box);ui->label17->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label17->setText(" ");ui->label17->setFrameStyle(QFrame::Box);ui->label17->setAlignment(Qt::AlignCenter);} i++;

            ui->label18->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label18->setPixmap(PA);ui->label18->setFrameStyle(QFrame::Box);ui->label18->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label18->setPixmap(PN);ui->label18->setFrameStyle(QFrame::Box);ui->label18->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label18->setPixmap(DA);ui->label18->setFrameStyle(QFrame::Box);ui->label18->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label18->setPixmap(DN);ui->label18->setFrameStyle(QFrame::Box);ui->label18->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label18->setText(" ");ui->label18->setFrameStyle(QFrame::Box);ui->label18->setAlignment(Qt::AlignCenter);} i++;

            ui->label21->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label21->setPixmap(PA);ui->label21->setFrameStyle(QFrame::Box);ui->label21->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label21->setPixmap(PN);ui->label21->setFrameStyle(QFrame::Box);ui->label21->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label21->setPixmap(DA);ui->label21->setFrameStyle(QFrame::Box);ui->label21->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label21->setPixmap(DN);ui->label21->setFrameStyle(QFrame::Box);ui->label21->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label21->setText(" ");ui->label21->setFrameStyle(QFrame::Box);ui->label21->setAlignment(Qt::AlignCenter);} i++;

            ui->label22->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label22->setPixmap(PA);ui->label22->setFrameStyle(QFrame::Box);ui->label22->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label22->setPixmap(PN);ui->label22->setFrameStyle(QFrame::Box);ui->label22->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label22->setPixmap(DA);ui->label22->setFrameStyle(QFrame::Box);ui->label22->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label22->setPixmap(DN);ui->label22->setFrameStyle(QFrame::Box);ui->label22->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label22->setText(" ");ui->label22->setFrameStyle(QFrame::Box);ui->label22->setAlignment(Qt::AlignCenter);} i++;

            ui->label23->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label23->setPixmap(PA);ui->label23->setFrameStyle(QFrame::Box);ui->label23->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label23->setPixmap(PN);ui->label23->setFrameStyle(QFrame::Box);ui->label23->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label23->setPixmap(DA);ui->label23->setFrameStyle(QFrame::Box);ui->label23->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label23->setPixmap(DN);ui->label23->setFrameStyle(QFrame::Box);ui->label23->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label23->setText(" ");ui->label23->setFrameStyle(QFrame::Box);ui->label23->setAlignment(Qt::AlignCenter);} i++;

            ui->label24->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label24->setPixmap(PA);ui->label24->setFrameStyle(QFrame::Box);ui->label24->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label24->setPixmap(PN);ui->label24->setFrameStyle(QFrame::Box);ui->label24->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label24->setPixmap(DA);ui->label24->setFrameStyle(QFrame::Box);ui->label24->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label24->setPixmap(DN);ui->label24->setFrameStyle(QFrame::Box);ui->label24->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label24->setText(" ");ui->label24->setFrameStyle(QFrame::Box);ui->label24->setAlignment(Qt::AlignCenter);} i++;

            ui->label25->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label25->setPixmap(PA);ui->label25->setFrameStyle(QFrame::Box);ui->label25->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label25->setPixmap(PN);ui->label25->setFrameStyle(QFrame::Box);ui->label25->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label25->setPixmap(DA);ui->label25->setFrameStyle(QFrame::Box);ui->label25->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label25->setPixmap(DN);ui->label25->setFrameStyle(QFrame::Box);ui->label25->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label25->setText(" ");ui->label25->setFrameStyle(QFrame::Box);ui->label25->setAlignment(Qt::AlignCenter);} i++;

            ui->label26->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label26->setPixmap(PA);ui->label26->setFrameStyle(QFrame::Box);ui->label26->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label26->setPixmap(PN);ui->label26->setFrameStyle(QFrame::Box);ui->label26->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label26->setPixmap(DA);ui->label26->setFrameStyle(QFrame::Box);ui->label26->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label26->setPixmap(DN);ui->label26->setFrameStyle(QFrame::Box);ui->label26->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label26->setText(" ");ui->label26->setFrameStyle(QFrame::Box);ui->label26->setAlignment(Qt::AlignCenter);} i++;

            ui->label27->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label27->setPixmap(PA);ui->label27->setFrameStyle(QFrame::Box);ui->label27->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label27->setPixmap(PN);ui->label27->setFrameStyle(QFrame::Box);ui->label27->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label27->setPixmap(DA);ui->label27->setFrameStyle(QFrame::Box);ui->label27->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label27->setPixmap(DN);ui->label27->setFrameStyle(QFrame::Box);ui->label27->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label27->setText(" ");ui->label27->setFrameStyle(QFrame::Box);ui->label27->setAlignment(Qt::AlignCenter);} i++;

            ui->label28->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label28->setPixmap(PA);ui->label28->setFrameStyle(QFrame::Box);ui->label28->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label28->setPixmap(PN);ui->label28->setFrameStyle(QFrame::Box);ui->label28->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label28->setPixmap(DA);ui->label28->setFrameStyle(QFrame::Box);ui->label28->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label28->setPixmap(DN);ui->label28->setFrameStyle(QFrame::Box);ui->label28->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label28->setText(" ");ui->label28->setFrameStyle(QFrame::Box);ui->label28->setAlignment(Qt::AlignCenter);} i++;

            ui->label31->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label31->setPixmap(PA);ui->label31->setFrameStyle(QFrame::Box);ui->label31->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label31->setPixmap(PN);ui->label31->setFrameStyle(QFrame::Box);ui->label31->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label31->setPixmap(DA);ui->label31->setFrameStyle(QFrame::Box);ui->label31->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label31->setPixmap(DN);ui->label31->setFrameStyle(QFrame::Box);ui->label31->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label31->setText(" ");ui->label31->setFrameStyle(QFrame::Box);ui->label31->setAlignment(Qt::AlignCenter);} i++;

            ui->label32->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label32->setPixmap(PA);ui->label32->setFrameStyle(QFrame::Box);ui->label32->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label32->setPixmap(PN);ui->label32->setFrameStyle(QFrame::Box);ui->label32->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label32->setPixmap(DA);ui->label32->setFrameStyle(QFrame::Box);ui->label32->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label32->setPixmap(DN);ui->label32->setFrameStyle(QFrame::Box);ui->label32->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label32->setText(" ");ui->label32->setFrameStyle(QFrame::Box);ui->label32->setAlignment(Qt::AlignCenter);} i++;

            ui->label33->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label33->setPixmap(PA);ui->label33->setFrameStyle(QFrame::Box);ui->label33->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label33->setPixmap(PN);ui->label33->setFrameStyle(QFrame::Box);ui->label33->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label33->setPixmap(DA);ui->label33->setFrameStyle(QFrame::Box);ui->label33->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label33->setPixmap(DN);ui->label33->setFrameStyle(QFrame::Box);ui->label33->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label33->setText(" ");ui->label33->setFrameStyle(QFrame::Box);ui->label33->setAlignment(Qt::AlignCenter);} i++;

            ui->label34->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label34->setPixmap(PA);ui->label34->setFrameStyle(QFrame::Box);ui->label34->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label34->setPixmap(PN);ui->label34->setFrameStyle(QFrame::Box);ui->label34->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label34->setPixmap(DA);ui->label34->setFrameStyle(QFrame::Box);ui->label34->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label34->setPixmap(DN);ui->label34->setFrameStyle(QFrame::Box);ui->label34->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label34->setText(" ");ui->label34->setFrameStyle(QFrame::Box);ui->label34->setAlignment(Qt::AlignCenter);} i++;

            ui->label35->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label35->setPixmap(PA);ui->label35->setFrameStyle(QFrame::Box);ui->label35->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label35->setPixmap(PN);ui->label35->setFrameStyle(QFrame::Box);ui->label35->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label35->setPixmap(DA);ui->label35->setFrameStyle(QFrame::Box);ui->label35->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label35->setPixmap(DN);ui->label35->setFrameStyle(QFrame::Box);ui->label35->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label35->setText(" ");ui->label35->setFrameStyle(QFrame::Box);ui->label35->setAlignment(Qt::AlignCenter);} i++;

            ui->label36->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label36->setPixmap(PA);ui->label36->setFrameStyle(QFrame::Box);ui->label36->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label36->setPixmap(PN);ui->label36->setFrameStyle(QFrame::Box);ui->label36->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label36->setPixmap(DA);ui->label36->setFrameStyle(QFrame::Box);ui->label36->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label36->setPixmap(DN);ui->label36->setFrameStyle(QFrame::Box);ui->label36->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label36->setText(" ");ui->label36->setFrameStyle(QFrame::Box);ui->label36->setAlignment(Qt::AlignCenter);} i++;

            ui->label37->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label37->setPixmap(PA);ui->label37->setFrameStyle(QFrame::Box);ui->label37->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label37->setPixmap(PN);ui->label37->setFrameStyle(QFrame::Box);ui->label37->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label37->setPixmap(DA);ui->label37->setFrameStyle(QFrame::Box);ui->label37->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label37->setPixmap(DN);ui->label37->setFrameStyle(QFrame::Box);ui->label37->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label37->setText(" ");ui->label37->setFrameStyle(QFrame::Box);ui->label37->setAlignment(Qt::AlignCenter);} i++;

            ui->label38->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label38->setPixmap(PA);ui->label38->setFrameStyle(QFrame::Box);ui->label38->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label38->setPixmap(PN);ui->label38->setFrameStyle(QFrame::Box);ui->label38->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label38->setPixmap(DA);ui->label38->setFrameStyle(QFrame::Box);ui->label38->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label38->setPixmap(DN);ui->label38->setFrameStyle(QFrame::Box);ui->label38->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label38->setText(" ");ui->label38->setFrameStyle(QFrame::Box);ui->label38->setAlignment(Qt::AlignCenter);} i++;

            ui->label41->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label41->setPixmap(PA);ui->label41->setFrameStyle(QFrame::Box);ui->label41->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label41->setPixmap(PN);ui->label41->setFrameStyle(QFrame::Box);ui->label41->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label41->setPixmap(DA);ui->label41->setFrameStyle(QFrame::Box);ui->label41->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label41->setPixmap(DN);ui->label41->setFrameStyle(QFrame::Box);ui->label41->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label41->setText(" ");ui->label41->setFrameStyle(QFrame::Box);ui->label41->setAlignment(Qt::AlignCenter);} i++;

            ui->label42->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label42->setPixmap(PA);ui->label42->setFrameStyle(QFrame::Box);ui->label42->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label42->setPixmap(PN);ui->label42->setFrameStyle(QFrame::Box);ui->label42->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label42->setPixmap(DA);ui->label42->setFrameStyle(QFrame::Box);ui->label42->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label42->setPixmap(DN);ui->label42->setFrameStyle(QFrame::Box);ui->label42->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label42->setText(" ");ui->label42->setFrameStyle(QFrame::Box);ui->label42->setAlignment(Qt::AlignCenter);} i++;

            ui->label43->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label43->setPixmap(PA);ui->label43->setFrameStyle(QFrame::Box);ui->label43->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label43->setPixmap(PN);ui->label43->setFrameStyle(QFrame::Box);ui->label43->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label43->setPixmap(DA);ui->label43->setFrameStyle(QFrame::Box);ui->label43->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label43->setPixmap(DN);ui->label43->setFrameStyle(QFrame::Box);ui->label43->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label43->setText(" ");ui->label43->setFrameStyle(QFrame::Box);ui->label43->setAlignment(Qt::AlignCenter);} i++;

            ui->label44->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label44->setPixmap(PA);ui->label44->setFrameStyle(QFrame::Box);ui->label44->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label44->setPixmap(PN);ui->label44->setFrameStyle(QFrame::Box);ui->label44->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label44->setPixmap(DA);ui->label44->setFrameStyle(QFrame::Box);ui->label44->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label44->setPixmap(DN);ui->label44->setFrameStyle(QFrame::Box);ui->label44->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label44->setText(" ");ui->label44->setFrameStyle(QFrame::Box);ui->label44->setAlignment(Qt::AlignCenter);} i++;

            ui->label45->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label45->setPixmap(PA);ui->label45->setFrameStyle(QFrame::Box);ui->label45->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label45->setPixmap(PN);ui->label45->setFrameStyle(QFrame::Box);ui->label45->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label45->setPixmap(DA);ui->label45->setFrameStyle(QFrame::Box);ui->label45->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label45->setPixmap(DN);ui->label45->setFrameStyle(QFrame::Box);ui->label45->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label45->setText(" ");ui->label45->setFrameStyle(QFrame::Box);ui->label45->setAlignment(Qt::AlignCenter);} i++;

            ui->label46->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label46->setPixmap(PA);ui->label46->setFrameStyle(QFrame::Box);ui->label46->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label46->setPixmap(PN);ui->label46->setFrameStyle(QFrame::Box);ui->label46->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label46->setPixmap(DA);ui->label46->setFrameStyle(QFrame::Box);ui->label46->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label46->setPixmap(DN);ui->label46->setFrameStyle(QFrame::Box);ui->label46->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label46->setText(" ");ui->label46->setFrameStyle(QFrame::Box);ui->label46->setAlignment(Qt::AlignCenter);} i++;

            ui->label47->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label47->setPixmap(PA);ui->label47->setFrameStyle(QFrame::Box);ui->label47->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label47->setPixmap(PN);ui->label47->setFrameStyle(QFrame::Box);ui->label47->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label47->setPixmap(DA);ui->label47->setFrameStyle(QFrame::Box);ui->label47->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label47->setPixmap(DN);ui->label47->setFrameStyle(QFrame::Box);ui->label47->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label47->setText(" ");ui->label47->setFrameStyle(QFrame::Box);ui->label47->setAlignment(Qt::AlignCenter);} i++;

            ui->label48->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label48->setPixmap(PA);ui->label48->setFrameStyle(QFrame::Box);ui->label48->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label48->setPixmap(PN);ui->label48->setFrameStyle(QFrame::Box);ui->label48->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label48->setPixmap(DA);ui->label48->setFrameStyle(QFrame::Box);ui->label48->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label48->setPixmap(DN);ui->label48->setFrameStyle(QFrame::Box);ui->label48->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label48->setText(" ");ui->label48->setFrameStyle(QFrame::Box);ui->label48->setAlignment(Qt::AlignCenter);} i++;

            ui->label51->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label51->setPixmap(PA);ui->label51->setFrameStyle(QFrame::Box);ui->label51->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label51->setPixmap(PN);ui->label51->setFrameStyle(QFrame::Box);ui->label51->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label51->setPixmap(DA);ui->label51->setFrameStyle(QFrame::Box);ui->label51->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label51->setPixmap(DN);ui->label51->setFrameStyle(QFrame::Box);ui->label51->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label51->setText(" ");ui->label51->setFrameStyle(QFrame::Box);ui->label51->setAlignment(Qt::AlignCenter);} i++;

            ui->label52->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label52->setPixmap(PA);ui->label52->setFrameStyle(QFrame::Box);ui->label52->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label52->setPixmap(PN);ui->label52->setFrameStyle(QFrame::Box);ui->label52->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label52->setPixmap(DA);ui->label52->setFrameStyle(QFrame::Box);ui->label52->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label52->setPixmap(DN);ui->label52->setFrameStyle(QFrame::Box);ui->label52->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label52->setText(" ");ui->label52->setFrameStyle(QFrame::Box);ui->label52->setAlignment(Qt::AlignCenter);} i++;

            ui->label53->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label53->setPixmap(PA);ui->label53->setFrameStyle(QFrame::Box);ui->label53->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label53->setPixmap(PN);ui->label53->setFrameStyle(QFrame::Box);ui->label53->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label53->setPixmap(DA);ui->label53->setFrameStyle(QFrame::Box);ui->label53->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label53->setPixmap(DN);ui->label53->setFrameStyle(QFrame::Box);ui->label53->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label53->setText(" ");ui->label53->setFrameStyle(QFrame::Box);ui->label53->setAlignment(Qt::AlignCenter);} i++;

            ui->label54->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label54->setPixmap(PA);ui->label54->setFrameStyle(QFrame::Box);ui->label54->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label54->setPixmap(PN);ui->label54->setFrameStyle(QFrame::Box);ui->label54->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label54->setPixmap(DA);ui->label54->setFrameStyle(QFrame::Box);ui->label54->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label54->setPixmap(DN);ui->label54->setFrameStyle(QFrame::Box);ui->label54->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label54->setText(" ");ui->label54->setFrameStyle(QFrame::Box);ui->label54->setAlignment(Qt::AlignCenter);} i++;

            ui->label55->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label55->setPixmap(PA);ui->label55->setFrameStyle(QFrame::Box);ui->label55->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label55->setPixmap(PN);ui->label55->setFrameStyle(QFrame::Box);ui->label55->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label55->setPixmap(DA);ui->label55->setFrameStyle(QFrame::Box);ui->label55->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label55->setPixmap(DN);ui->label55->setFrameStyle(QFrame::Box);ui->label55->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label55->setText(" ");ui->label55->setFrameStyle(QFrame::Box);ui->label55->setAlignment(Qt::AlignCenter);} i++;

            ui->label56->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label56->setPixmap(PA);ui->label56->setFrameStyle(QFrame::Box);ui->label56->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label56->setPixmap(PN);ui->label56->setFrameStyle(QFrame::Box);ui->label56->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label56->setPixmap(DA);ui->label56->setFrameStyle(QFrame::Box);ui->label56->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label56->setPixmap(DN);ui->label56->setFrameStyle(QFrame::Box);ui->label56->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label56->setText(" ");ui->label56->setFrameStyle(QFrame::Box);ui->label56->setAlignment(Qt::AlignCenter);} i++;

            ui->label57->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label57->setPixmap(PA);ui->label57->setFrameStyle(QFrame::Box);ui->label57->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label57->setPixmap(PN);ui->label57->setFrameStyle(QFrame::Box);ui->label57->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label57->setPixmap(DA);ui->label57->setFrameStyle(QFrame::Box);ui->label57->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label57->setPixmap(DN);ui->label57->setFrameStyle(QFrame::Box);ui->label57->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label57->setText(" ");ui->label57->setFrameStyle(QFrame::Box);ui->label57->setAlignment(Qt::AlignCenter);} i++;

            ui->label58->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label58->setPixmap(PA);ui->label58->setFrameStyle(QFrame::Box);ui->label58->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label58->setPixmap(PN);ui->label58->setFrameStyle(QFrame::Box);ui->label58->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label58->setPixmap(DA);ui->label58->setFrameStyle(QFrame::Box);ui->label58->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label58->setPixmap(DN);ui->label58->setFrameStyle(QFrame::Box);ui->label58->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label58->setText(" ");ui->label58->setFrameStyle(QFrame::Box);ui->label58->setAlignment(Qt::AlignCenter);} i++;

            ui->label61->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label61->setPixmap(PA);ui->label61->setFrameStyle(QFrame::Box);ui->label61->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label61->setPixmap(PN);ui->label61->setFrameStyle(QFrame::Box);ui->label61->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label61->setPixmap(DA);ui->label61->setFrameStyle(QFrame::Box);ui->label61->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label61->setPixmap(DN);ui->label61->setFrameStyle(QFrame::Box);ui->label61->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label61->setText(" ");ui->label61->setFrameStyle(QFrame::Box);ui->label61->setAlignment(Qt::AlignCenter);} i++;

            ui->label62->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label62->setPixmap(PA);ui->label62->setFrameStyle(QFrame::Box);ui->label62->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label62->setPixmap(PN);ui->label62->setFrameStyle(QFrame::Box);ui->label62->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label62->setPixmap(DA);ui->label62->setFrameStyle(QFrame::Box);ui->label62->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label62->setPixmap(DN);ui->label62->setFrameStyle(QFrame::Box);ui->label62->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label62->setText(" ");ui->label62->setFrameStyle(QFrame::Box);ui->label62->setAlignment(Qt::AlignCenter);} i++;

            ui->label63->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label63->setPixmap(PA);ui->label63->setFrameStyle(QFrame::Box);ui->label63->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label63->setPixmap(PN);ui->label63->setFrameStyle(QFrame::Box);ui->label63->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label63->setPixmap(DA);ui->label63->setFrameStyle(QFrame::Box);ui->label63->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label63->setPixmap(DN);ui->label63->setFrameStyle(QFrame::Box);ui->label63->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label63->setText(" ");ui->label63->setFrameStyle(QFrame::Box);ui->label63->setAlignment(Qt::AlignCenter);} i++;

            ui->label64->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label64->setPixmap(PA);ui->label64->setFrameStyle(QFrame::Box);ui->label64->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label64->setPixmap(PN);ui->label64->setFrameStyle(QFrame::Box);ui->label64->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label64->setPixmap(DA);ui->label64->setFrameStyle(QFrame::Box);ui->label64->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label64->setPixmap(DN);ui->label64->setFrameStyle(QFrame::Box);ui->label64->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label64->setText(" ");ui->label64->setFrameStyle(QFrame::Box);ui->label64->setAlignment(Qt::AlignCenter);} i++;

            ui->label65->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label65->setPixmap(PA);ui->label65->setFrameStyle(QFrame::Box);ui->label65->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label65->setPixmap(PN);ui->label65->setFrameStyle(QFrame::Box);ui->label65->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label65->setPixmap(DA);ui->label65->setFrameStyle(QFrame::Box);ui->label65->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label65->setPixmap(DN);ui->label65->setFrameStyle(QFrame::Box);ui->label65->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label65->setText(" ");ui->label65->setFrameStyle(QFrame::Box);ui->label65->setAlignment(Qt::AlignCenter);} i++;

            ui->label66->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label66->setPixmap(PA);ui->label66->setFrameStyle(QFrame::Box);ui->label66->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label66->setPixmap(PN);ui->label66->setFrameStyle(QFrame::Box);ui->label66->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label66->setPixmap(DA);ui->label66->setFrameStyle(QFrame::Box);ui->label66->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label66->setPixmap(DN);ui->label66->setFrameStyle(QFrame::Box);ui->label66->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label66->setText(" ");ui->label66->setFrameStyle(QFrame::Box);ui->label66->setAlignment(Qt::AlignCenter);} i++;

            ui->label67->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label67->setPixmap(PA);ui->label67->setFrameStyle(QFrame::Box);ui->label67->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label67->setPixmap(PN);ui->label67->setFrameStyle(QFrame::Box);ui->label67->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label67->setPixmap(DA);ui->label67->setFrameStyle(QFrame::Box);ui->label67->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label67->setPixmap(DN);ui->label67->setFrameStyle(QFrame::Box);ui->label67->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label67->setText(" ");ui->label67->setFrameStyle(QFrame::Box);ui->label67->setAlignment(Qt::AlignCenter);} i++;

            ui->label68->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label68->setPixmap(PA);ui->label68->setFrameStyle(QFrame::Box);ui->label68->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label68->setPixmap(PN);ui->label68->setFrameStyle(QFrame::Box);ui->label68->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label68->setPixmap(DA);ui->label68->setFrameStyle(QFrame::Box);ui->label68->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label68->setPixmap(DN);ui->label68->setFrameStyle(QFrame::Box);ui->label68->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label68->setText(" ");ui->label68->setFrameStyle(QFrame::Box);ui->label68->setAlignment(Qt::AlignCenter);} i++;

            ui->label71->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label71->setPixmap(PA);ui->label71->setFrameStyle(QFrame::Box);ui->label71->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label71->setPixmap(PN);ui->label71->setFrameStyle(QFrame::Box);ui->label71->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label71->setPixmap(DA);ui->label71->setFrameStyle(QFrame::Box);ui->label71->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label71->setPixmap(DN);ui->label71->setFrameStyle(QFrame::Box);ui->label71->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label71->setText(" ");ui->label71->setFrameStyle(QFrame::Box);ui->label71->setAlignment(Qt::AlignCenter);} i++;

            ui->label72->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label72->setPixmap(PA);ui->label72->setFrameStyle(QFrame::Box);ui->label72->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label72->setPixmap(PN);ui->label72->setFrameStyle(QFrame::Box);ui->label72->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label72->setPixmap(DA);ui->label72->setFrameStyle(QFrame::Box);ui->label72->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label72->setPixmap(DN);ui->label72->setFrameStyle(QFrame::Box);ui->label72->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label72->setText(" ");ui->label72->setFrameStyle(QFrame::Box);ui->label72->setAlignment(Qt::AlignCenter);} i++;

            ui->label73->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label73->setPixmap(PA);ui->label73->setFrameStyle(QFrame::Box);ui->label73->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label73->setPixmap(PN);ui->label73->setFrameStyle(QFrame::Box);ui->label73->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label73->setPixmap(DA);ui->label73->setFrameStyle(QFrame::Box);ui->label73->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label73->setPixmap(DN);ui->label73->setFrameStyle(QFrame::Box);ui->label73->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label73->setText(" ");ui->label73->setFrameStyle(QFrame::Box);ui->label73->setAlignment(Qt::AlignCenter);} i++;

            ui->label74->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label74->setPixmap(PA);ui->label74->setFrameStyle(QFrame::Box);ui->label74->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label74->setPixmap(PN);ui->label74->setFrameStyle(QFrame::Box);ui->label74->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label74->setPixmap(DA);ui->label74->setFrameStyle(QFrame::Box);ui->label74->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label74->setPixmap(DN);ui->label74->setFrameStyle(QFrame::Box);ui->label74->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label74->setText(" ");ui->label74->setFrameStyle(QFrame::Box);ui->label74->setAlignment(Qt::AlignCenter);} i++;

            ui->label75->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label75->setPixmap(PA);ui->label75->setFrameStyle(QFrame::Box);ui->label75->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label75->setPixmap(PN);ui->label75->setFrameStyle(QFrame::Box);ui->label75->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label75->setPixmap(DA);ui->label75->setFrameStyle(QFrame::Box);ui->label75->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label75->setPixmap(DN);ui->label75->setFrameStyle(QFrame::Box);ui->label75->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label75->setText(" ");ui->label75->setFrameStyle(QFrame::Box);ui->label75->setAlignment(Qt::AlignCenter);} i++;

            ui->label76->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label76->setPixmap(PA);ui->label76->setFrameStyle(QFrame::Box);ui->label76->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label76->setPixmap(PN);ui->label76->setFrameStyle(QFrame::Box);ui->label76->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label76->setPixmap(DA);ui->label76->setFrameStyle(QFrame::Box);ui->label76->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label76->setPixmap(DN);ui->label76->setFrameStyle(QFrame::Box);ui->label76->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label76->setText(" ");ui->label76->setFrameStyle(QFrame::Box);ui->label76->setAlignment(Qt::AlignCenter);} i++;

            ui->label77->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label77->setPixmap(PA);ui->label77->setFrameStyle(QFrame::Box);ui->label77->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label77->setPixmap(PN);ui->label77->setFrameStyle(QFrame::Box);ui->label77->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label77->setPixmap(DA);ui->label77->setFrameStyle(QFrame::Box);ui->label77->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label77->setPixmap(DN);ui->label77->setFrameStyle(QFrame::Box);ui->label77->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label77->setText(" ");ui->label77->setFrameStyle(QFrame::Box);ui->label77->setAlignment(Qt::AlignCenter);} i++;

            ui->label78->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label78->setPixmap(PA);ui->label78->setFrameStyle(QFrame::Box);ui->label78->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label78->setPixmap(PN);ui->label78->setFrameStyle(QFrame::Box);ui->label78->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label78->setPixmap(DA);ui->label78->setFrameStyle(QFrame::Box);ui->label78->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label78->setPixmap(DN);ui->label78->setFrameStyle(QFrame::Box);ui->label78->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label78->setText(" ");ui->label78->setFrameStyle(QFrame::Box);ui->label78->setAlignment(Qt::AlignCenter);} i++;

            ui->label81->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label81->setPixmap(PA);ui->label81->setFrameStyle(QFrame::Box);ui->label81->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label81->setPixmap(PN);ui->label81->setFrameStyle(QFrame::Box);ui->label81->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label81->setPixmap(DA);ui->label81->setFrameStyle(QFrame::Box);ui->label81->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label81->setPixmap(DN);ui->label81->setFrameStyle(QFrame::Box);ui->label81->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label81->setText(" ");ui->label81->setFrameStyle(QFrame::Box);ui->label81->setAlignment(Qt::AlignCenter);} i++;

            ui->label82->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label82->setPixmap(PA);ui->label82->setFrameStyle(QFrame::Box);ui->label82->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label82->setPixmap(PN);ui->label82->setFrameStyle(QFrame::Box);ui->label82->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label82->setPixmap(DA);ui->label82->setFrameStyle(QFrame::Box);ui->label82->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label82->setPixmap(DN);ui->label82->setFrameStyle(QFrame::Box);ui->label82->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label82->setText(" ");ui->label82->setFrameStyle(QFrame::Box);ui->label82->setAlignment(Qt::AlignCenter);} i++;

            ui->label83->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label83->setPixmap(PA);ui->label83->setFrameStyle(QFrame::Box);ui->label83->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label83->setPixmap(PN);ui->label83->setFrameStyle(QFrame::Box);ui->label83->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label83->setPixmap(DA);ui->label83->setFrameStyle(QFrame::Box);ui->label83->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label83->setPixmap(DN);ui->label83->setFrameStyle(QFrame::Box);ui->label83->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label83->setText(" ");ui->label83->setFrameStyle(QFrame::Box);ui->label83->setAlignment(Qt::AlignCenter);} i++;

            ui->label84->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label84->setPixmap(PA);ui->label84->setFrameStyle(QFrame::Box);ui->label84->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label84->setPixmap(PN);ui->label84->setFrameStyle(QFrame::Box);ui->label84->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label84->setPixmap(DA);ui->label84->setFrameStyle(QFrame::Box);ui->label84->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label84->setPixmap(DN);ui->label84->setFrameStyle(QFrame::Box);ui->label84->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label84->setText(" ");ui->label84->setFrameStyle(QFrame::Box);ui->label84->setAlignment(Qt::AlignCenter);} i++;

            ui->label85->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label85->setPixmap(PA);ui->label85->setFrameStyle(QFrame::Box);ui->label85->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label85->setPixmap(PN);ui->label85->setFrameStyle(QFrame::Box);ui->label85->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label85->setPixmap(DA);ui->label85->setFrameStyle(QFrame::Box);ui->label85->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label85->setPixmap(DN);ui->label85->setFrameStyle(QFrame::Box);ui->label85->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label85->setText(" ");ui->label85->setFrameStyle(QFrame::Box);ui->label85->setAlignment(Qt::AlignCenter);} i++;

            ui->label86->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label86->setPixmap(PA);ui->label86->setFrameStyle(QFrame::Box);ui->label86->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label86->setPixmap(PN);ui->label86->setFrameStyle(QFrame::Box);ui->label86->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label86->setPixmap(DA);ui->label86->setFrameStyle(QFrame::Box);ui->label86->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label86->setPixmap(DN);ui->label86->setFrameStyle(QFrame::Box);ui->label86->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label86->setText(" ");ui->label86->setFrameStyle(QFrame::Box);ui->label86->setAlignment(Qt::AlignCenter);} i++;

            ui->label87->setStyleSheet("QLabel{background-color:brown;color:black}");
            if (msg[i]=='1'){ui->label87->setPixmap(PA);ui->label87->setFrameStyle(QFrame::Box);ui->label87->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label87->setPixmap(PN);ui->label87->setFrameStyle(QFrame::Box);ui->label87->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label87->setPixmap(DA);ui->label87->setFrameStyle(QFrame::Box);ui->label87->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label87->setPixmap(DN);ui->label87->setFrameStyle(QFrame::Box);ui->label87->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label87->setText(" ");ui->label87->setFrameStyle(QFrame::Box);ui->label87->setAlignment(Qt::AlignCenter);} i++;

            ui->label88->setStyleSheet("QLabel{background-color:yellow;color:black}");
            if (msg[i]=='1'){ui->label88->setPixmap(PA);ui->label88->setFrameStyle(QFrame::Box);ui->label88->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='2'){ui->label88->setPixmap(PN);ui->label88->setFrameStyle(QFrame::Box);ui->label88->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='3'){ui->label88->setPixmap(DA);ui->label88->setFrameStyle(QFrame::Box);ui->label88->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='4'){ui->label88->setPixmap(DN);ui->label88->setFrameStyle(QFrame::Box);ui->label88->setAlignment(Qt::AlignCenter);}
        else if(msg[i]=='0'){ui->label88->setText(" ");ui->label88->setFrameStyle(QFrame::Box);ui->label88->setAlignment(Qt::AlignCenter);} i++;
        char turn[20];
        int n=strlen(msg)+1;
        for(i;i<=n;i++)
        {
            turn[i-64]=msg[i];
        }
        turn[i-64]='/0';
        ui->labelTurn->setText(turn);
    }
    else
    {
        ui->labelTurn->setText(msg);
        hide();
        gameOver=true;

    }
}

void lgame::mousePressEvent(QMouseEvent *event)
{
    if(!gameOver)
    {
    if(event->button()==Qt::LeftButton)
     {
        if (FirstClick==true)
        {
            FirstCoordx=event->x();
            FirstCoordy=event->y();
            FirstClick=false;
        }
        else
        {
            SecondCoordx=event->x();
            SecondCoordy=event->y();
            FirstClick=true;
            update();
        }
    }
    if(SecondCoordx!=-1)
        {
        char msg[100],s;
        int x1,y1,x2,y2;
        y1=FirstCoordx/83+1;
        x1=FirstCoordy/49+1;
        y2=SecondCoordx/83+1;
        x2=SecondCoordy/49+1;

        std::string tmp=std::to_string(x1);
        const char* t=tmp.c_str();
        strcpy(msg,t);
        std::string tmp1=std::to_string(y1);
        const char* t1=tmp1.c_str();
        strcat(msg,t1);
        std::string tmp2=std::to_string(x2);
        const char* t2=tmp2.c_str();
        strcat(msg,t2);
        std::string tmp3=std::to_string(y2);
        const char* t3=tmp3.c_str();
        strcat(msg,t3);
        msg[strlen(msg)+1]='\0';
        FirstCoordx=-1;
        FirstCoordy=-1;
        SecondCoordx=-1;
        SecondCoordy=-1;
        write(my_sd,msg,100);
        hide();
        lgame *nextframe;
        nextframe=new lgame(this);
        nextframe->show();
        }
    }
}

void lgame::on_pushButton_clicked()
{
    char msg[100];
    strcpy(msg,"back");
    write(my_sd,msg,100);
    hide();
    MainMenu *back=new MainMenu();
    back->show();
}

