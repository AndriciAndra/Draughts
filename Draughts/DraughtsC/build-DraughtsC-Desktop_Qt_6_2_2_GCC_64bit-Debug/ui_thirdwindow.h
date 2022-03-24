/********************************************************************************
** Form generated from reading UI file 'thirdwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDWINDOW_H
#define UI_THIRDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thirdwindow
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineUsernameSignup;

    void setupUi(QDialog *thirdwindow)
    {
        if (thirdwindow->objectName().isEmpty())
            thirdwindow->setObjectName(QString::fromUtf8("thirdwindow"));
        thirdwindow->resize(530, 418);
        groupBox = new QGroupBox(thirdwindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(120, 60, 261, 231));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 160, 161, 25));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 70, 223, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineUsernameSignup = new QLineEdit(widget);
        lineUsernameSignup->setObjectName(QString::fromUtf8("lineUsernameSignup"));

        horizontalLayout->addWidget(lineUsernameSignup);


        retranslateUi(thirdwindow);

        QMetaObject::connectSlotsByName(thirdwindow);
    } // setupUi

    void retranslateUi(QDialog *thirdwindow)
    {
        thirdwindow->setWindowTitle(QCoreApplication::translate("thirdwindow", "Sign Up Window", nullptr));
        groupBox->setTitle(QCoreApplication::translate("thirdwindow", "Sign Up", nullptr));
        pushButton->setText(QCoreApplication::translate("thirdwindow", "Go To Login Window", nullptr));
        label->setText(QCoreApplication::translate("thirdwindow", "Username:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thirdwindow: public Ui_thirdwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDOW_H
