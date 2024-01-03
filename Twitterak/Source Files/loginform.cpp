#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>
#include "QtCore"
#include "mainwindow.h"
#include <QApplication>
#include <anonyuser.h>
#include <gl.h>

loginForm::loginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginForm)
{
    ui->setupUi(this);
    ui->groupBox_2->hide();
}

loginForm::~loginForm()
{
    delete ui;
}

void loginForm::on_btn_regiser_login_click() {}

void loginForm::on_pushButton_7_clicked()
{

       if (ui->radioButton->isChecked()){

         OrgUser orguser;
         currentuser=&orguser;
         orguser.setUsername(ui->txtusername->text().toStdString());
         orguser.setBoss(ui->txtusername->text().toStdString());
         orguser.setPassword(ui->txtpass->text().toStdString());
         orguser.setMobile(ui->txtmobile->text().toStdString());
         orguser.setName(ui->txtname->text().toStdString());
         orguser.setCountry(ui->txtcountry->text().toStdString());

         string res=orguser.registerUsers();

         QMessageBox msgBox;
         msgBox.setText(QString::fromStdString(res));
         msgBox.setWindowTitle("Warning");
         msgBox.setIcon(QMessageBox::Information);
         msgBox.addButton(QMessageBox::Ok);
         msgBox.exec();

       }

       if (ui->radioButton_2->isChecked()){

         AnonyUser peruser;
         currentuser= &peruser;
         peruser.setUsername(ui->txtusername->text().toStdString());
         peruser.setPassword(ui->txtpass->text().toStdString());

         string res=peruser.registerUsers();

         QMessageBox msgBox;
         msgBox.setText(QString::fromStdString(res));
         msgBox.setWindowTitle("Warning");
         msgBox.setIcon(QMessageBox::Information);
         msgBox.addButton(QMessageBox::Ok);
         msgBox.exec();

       }

       if (ui->radioButton_3->isChecked()){

        PersonalUser peruser;
        currentuser= &peruser;
        peruser.setUsername(ui->txtusername->text().toStdString());
        peruser.setCompany(ui->txtboss->text().toStdString());
        peruser.setPassword(ui->txtpass->text().toStdString());
        peruser.setMobile(ui->txtmobile->text().toStdString());
        peruser.setName(ui->txtname->text().toStdString());
        peruser.setCountry(ui->txtcountry->text().toStdString());

        string res=peruser.registerUsers();

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(res));
        msgBox.setWindowTitle("Warning");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();

       }
}

void loginForm::on_pushButton_clicked()
{

    OrgUser orguser;
    currentuser=&orguser;
    string res=currentuser->login(ui->txtloginuser->text().toStdString(),ui->txtloginpass->text().toStdString());
    if (res=="* Register Was Successful"){
        appcurrentUser=ui->txtloginuser->text().toStdString();
        loginForm::hide();
        MainWindow *mainForm = new MainWindow;
        mainForm->show();

    } else{

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(res));
        msgBox.setWindowTitle("Warning");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.addButton(QMessageBox::Ok);

        // Show the message box
        msgBox.exec();
    }

}

void loginForm::on_radioButton_2_clicked() {}


void loginForm::on_pushButton_2_clicked()
{
    exit(0);
}

void loginForm::on_pushButton_8_clicked()
{

}

