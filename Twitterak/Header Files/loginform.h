#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include <orguser.h>
#include <user.h>
#include <personaluser.h>

namespace Ui {

class loginForm;

}

class loginForm : public QDialog
{
    Q_OBJECT

public:
    User *currentuser;
    explicit loginForm(QWidget *parent = nullptr);
    ~loginForm();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

private:
    void on_btn_regiser_login_click();
    Ui::loginForm *ui;
};

#endif // LOGINFORM_H
