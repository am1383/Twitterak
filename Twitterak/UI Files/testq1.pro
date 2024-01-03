QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anonyuser.cpp \
    gl.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    orguser.cpp \
    personaluser.cpp \
    selectedusers.cpp \
    tweet.cpp \
    user.cpp

HEADERS += \
    anonyuser.h \
    gl.h \
    loginform.h \
    mainwindow.h \
    orguser.h \
    personaluser.h \
    selectedusers.h \
    tweet.h \
    user.h

FORMS += \
    dialog.ui \
    loginform.ui \
    mainwindow.ui \
    selectedusers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
