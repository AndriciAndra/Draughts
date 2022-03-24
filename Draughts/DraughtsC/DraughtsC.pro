QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    gamewindow.cpp \
    lgame.cpp \
    lgamewindow.cpp \
    loginwinow.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    ranking.cpp \
    secondwindow.cpp \
    thirdwindow.cpp

HEADERS += \
    connection.h \
    game.h \
    gamewindow.h \
    lgame.h \
    lgamewindow.h \
    loginwinow.h \
    mainmenu.h \
    mainwindow.h \
    ranking.h \
    secondwindow.h \
    thirdwindow.h

FORMS += \
    game.ui \
    gamewindow.ui \
    lgame.ui \
    lgamewindow.ui \
    loginwinow.ui \
    mainmenu.ui \
    mainwindow.ui \
    ranking.ui \
    secondwindow.ui \
    thirdwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
