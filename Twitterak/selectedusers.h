#ifndef SELECTEDUSERS_H
#define SELECTEDUSERS_H

#include <QDialog>

namespace Ui {

class SelectedUsers;

}

class SelectedUsers : public QDialog
{
    Q_OBJECT

public:
    explicit SelectedUsers(QWidget *parent = nullptr);
    ~SelectedUsers();

private slots:
    void on_lvalltweet_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_btnlike_clicked();

    void on_btndislike_clicked();

    void on_btnfollow_clicked();

    void on_btnunfollow_clicked();

private:
    Ui::SelectedUsers *ui;
};

#endif // SELECTEDUSERS_H
