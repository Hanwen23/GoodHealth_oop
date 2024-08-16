QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dietscene.cpp \
    infoscene.cpp \
    main.cpp \
    logscene.cpp \
    mainwindow.cpp \
    signup.cpp \
    sleepscene.cpp \
    sportscene.cpp

HEADERS += \
    dietscene.h \
    infoscene.h \
    logscene.h \
    mainwindow.h \
    signup.h \
    sleepscene.h \
    sportscene.h

FORMS += \
    dietscene.ui \
    infoscene.ui \
    logscene.ui \
    mainwindow.ui \
    signup.ui \
    sleepscene.ui \
    sportscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
