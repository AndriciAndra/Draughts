/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ClasicDraughts;
    QPushButton *LosingDraughts;
    QPushButton *Ranking;
    QPushButton *Settings;
    QPushButton *Logout;
    QPushButton *exit;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(578, 480);
        MainMenu->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(MainMenu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 110, 181, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ClasicDraughts = new QPushButton(layoutWidget);
        ClasicDraughts->setObjectName(QString::fromUtf8("ClasicDraughts"));

        verticalLayout->addWidget(ClasicDraughts);

        LosingDraughts = new QPushButton(layoutWidget);
        LosingDraughts->setObjectName(QString::fromUtf8("LosingDraughts"));

        verticalLayout->addWidget(LosingDraughts);

        Ranking = new QPushButton(layoutWidget);
        Ranking->setObjectName(QString::fromUtf8("Ranking"));

        verticalLayout->addWidget(Ranking);

        Settings = new QPushButton(layoutWidget);
        Settings->setObjectName(QString::fromUtf8("Settings"));

        verticalLayout->addWidget(Settings);

        Logout = new QPushButton(layoutWidget);
        Logout->setObjectName(QString::fromUtf8("Logout"));

        verticalLayout->addWidget(Logout);

        exit = new QPushButton(layoutWidget);
        exit->setObjectName(QString::fromUtf8("exit"));

        verticalLayout->addWidget(exit);


        retranslateUi(MainMenu);
        QObject::connect(exit, &QPushButton::clicked, MainMenu, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Main Menu", nullptr));
        ClasicDraughts->setText(QCoreApplication::translate("MainMenu", "Clasic Draughts", nullptr));
        LosingDraughts->setText(QCoreApplication::translate("MainMenu", "Losing Draughts", nullptr));
        Ranking->setText(QCoreApplication::translate("MainMenu", "Ranking", nullptr));
        Settings->setText(QCoreApplication::translate("MainMenu", "Settings", nullptr));
        Logout->setText(QCoreApplication::translate("MainMenu", "Logout", nullptr));
        exit->setText(QCoreApplication::translate("MainMenu", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
