#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginform.h"


QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lvalluser_clicked(const QModelIndex &index);

    void on_btnsend_clicked();

    void on_pushButton_clicked();

    void on_lvalluser_doubleClicked(const QModelIndex &index);

    void on_btnselectimage_clicked();

    void on_btnselectbgimg_clicked();

    void on_btnapply_clicked();

    void on_btblogout_clicked();

    void on_pushButton_2_clicked();

    void on_btnprofile_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
