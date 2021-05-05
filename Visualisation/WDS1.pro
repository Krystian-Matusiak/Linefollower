QT       += core gui
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QT       += core gui charts
QT += charts
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DaneSensoryczne.cpp \
    DaneSilnikowe.cpp \
    Receiver.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    DaneSensoryczne.h \
    DaneSilnikowe.h \
    Receiver.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

RESOURCES +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ARROW_DOWN.png \
    ARROW_LEFT.png \
    ARROW_RIGHT.png \
    ARROW_UP.png \
    BAT_100.png \
    BAT_25.png \
    BAT_50.png \
    BAT_75.png \
    Dane_sensoryczne.txt \
    bk.jpg \
    greenarrow.png \
    redarrow.png
