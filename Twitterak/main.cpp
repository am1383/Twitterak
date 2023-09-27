#include "mainwindow.h"
#include "loginform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    loginForm Twitterak;
    Twitterak.show();
    return a.exec();
}

// Created By Pire Mard Khayat Team
