#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginform.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <iostream>
#include <user.h>
#include <gl.h>
#include <QDir>
#include <QStandardItem>
#include <tweet.h>
#include <fstream>
#include <QMessageBox>
#include <selectedusers.h>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <sstream>

QString filename;
QString bgfilename;
// How Much Following Do You Have
int countB (std::vector<std::string>& strings,string st) {
    int count = 0;
    for (const std::string& str : strings) {
        // Find the position of the first occurrence of '-'
        size_t pos = str.find('-');
        if (pos != std::string::npos && str.substr(pos + 1) == st) {
            // If 'b' is on the right side of '-', increment the count
            count++;
        }
    }
    return count;
}



bool fileExists( std::string filePath) {
    std::ifstream file(filePath); // Replace "filename.txt" with the name of the file you want to check

        if (file) {
            return true;
        } else {
            return false;
        }

}

QStandardItemModel *_model = new QStandardItemModel();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _model = new QStandardItemModel();
    ui->groupBox->hide();
    User *_currentUser=new  User();
    _currentUser->setUsername(appcurrentUser);

    _currentUser->loadProfile();

        if (_currentUser->_type=="Organisation"){

             ui->lblfollowingcount->hide();

             ui->label_4->hide();

        }


    ui->lblbio->setText(QString::fromStdString(_currentUser->getBio()));
    ui->lblname->setText(QString::fromStdString(_currentUser->getName()));
    ui->lblfollowingcount->setText(QString::fromStdString(to_string(_currentUser->getFollowing().size())));

    if (_currentUser->_type=="Anony"){

         ui->lblname->setText(QString::fromStdString("AnonyMouse"));

    }

    QPixmap newImage(QString::fromStdString(_currentUser->getImg()));
    QImage image(QString::fromStdString(_currentUser->getImg()));

        // Create a QGraphicsScene and set the new image as its background
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image)); // Create a QGraphicsPixmapItem
    QGraphicsScene* scene = new QGraphicsScene(ui->gwimg);

        scene->addItem(pixmapItem);

        // Set the new scene for the QGraphicsView

        ui->gwimg->setScene(scene);
        ui->gwimg->fitInView(pixmapItem, Qt::IgnoreAspectRatio);


        if (_currentUser->_type=="Anony"){

            QPixmap newImage(QString::fromStdString(_currentUser->getImg()));
            QImage image(QString::fromStdString("c:/anony/anony.jpg"));

                // Create a QGraphicsScene and set the new image as its background
            QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image)); // Create a QGraphicsPixmapItem
            QGraphicsScene* scene = new QGraphicsScene(ui->gwimg);

                scene->addItem(pixmapItem);

                // Set the new scene for the QGraphicsView

                ui->gwimg->setScene(scene);
                ui->gwimg->fitInView(pixmapItem, Qt::IgnoreAspectRatio);

        }


           QPixmap newImage1(QString::fromStdString(_currentUser->getBgImg()));

               // Create a QGraphicsScene and set the new image as its background
               QGraphicsScene* scene1 = new QGraphicsScene(ui->gwbimg);
               scene1->setBackgroundBrush(QBrush(newImage1));

               // Set the new scene for the QGraphicsView
               ui->gwbimg->setScene(scene1);


// Check Directory Path Except Realse, Debug, QTC_Calnged For Backlgorund Image Set
                QDir folderDir(QDir::currentPath());
                if (folderDir.exists()) {
                        QStringList subfolders = folderDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
                QStandardItemModel *model = new QStandardItemModel();
                        foreach (QString subfolder, subfolders) {
//                qDebug() << "Folder: " << subfolder;
                if (subfolder=="release" || subfolder=="debug" || subfolder==".qtc_clangd"  )
                {

                }else{


                    QStandardItem *item = new QStandardItem(subfolder);
                    model->appendRow(item);
                }

            }

            ui->lvalluser->setModel(model);
        }


    for (Tweet& tw : _currentUser->getTweet()) {

           Tweet tww;

           string td=tw.getId()+'-'+tw.getText();


           QStandardItem *item = new QStandardItem(QString::fromStdString(td));
           _model->appendRow(item);
            ui->lvtweet->setModel(_model);
       }



      std::ifstream file(_currentUser->getUsername()+"/following.txt");

      vector<string> followerlist;

       std::string line;
       while (std::getline(file, line)) {
          followerlist.push_back(line);
       }

       file.close();

          QStandardItemModel *model = new QStandardItemModel();


    for(string& st: followerlist){

        QStandardItem *item1 = new QStandardItem(QString::fromStdString(st));
        model->appendRow(item1);

    }

     ui->lvfollowing->setModel(model);

     vector<string> lst;

     std::ifstream file6("followers.txt");
     std::string line6;

          while (std::getline(file6, line6)) { // Read each line in the file
                lst.push_back(line6);
              }

            file6.close(); // Close the file

            int b=countB( lst,appcurrentUser);

            ui->lblfollowercount->setText(QString::fromStdString(to_string(b)));
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_lvalluser_clicked(const QModelIndex &index){}


void MainWindow::on_btnsend_clicked()
{
    User *_currentUser=new  User();
    _currentUser->setUsername(appcurrentUser);
    _currentUser->loadProfile();
    if(_currentUser->_type=="Anony"){

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("! Anony User Can Not Send Tweet"));
        msgBox.setWindowTitle("Warning");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return;

    }

    if(ui->txttweet->text().isEmpty()){
        return;

    }

// Show Tweets
    Tweet *tw=new Tweet();
    QString id=  tw->generateUniqueID();
    tw->setText(ui->txttweet->text().toStdString());

    QStandardItem *item = new QStandardItem(id+"-"+ui->txttweet->text());
    _model->appendRow(item);
    ui->lvtweet->setModel(_model);

    ui->txttweet->setText("");


    int rowCount = _model->rowCount();


      std::ofstream outFile4(appcurrentUser+"/tweet.txt", std::ios::out | std::ios::trunc);


        if (outFile4.is_open()) {

            for (int row = 0; row < rowCount; ++row) {

                 QModelIndex index = _model->index(row, 0);
                 QVariant data = _model->data(index);
                 QString itd=data.toString();

                 // Use the data as required
                 // For example:
                 outFile4 << itd.toStdString()<<std::endl;
                }

                outFile4.close();
        }
}

// Delete Selected Tweet
void MainWindow::on_pushButton_clicked()
{
    QModelIndex currentIndex = ui->lvtweet->currentIndex();
    _model->removeRow(currentIndex.row());


    int rowCount = _model->rowCount();


    std::ofstream outFile4(appcurrentUser+"/tweet.txt", std::ios::out | std::ios::trunc);


    if (outFile4.is_open()) {

        for (int row = 0; row < rowCount; ++row) {

                QModelIndex index = _model->index(row, 0);
                QVariant data = _model->data(index);
                QString itd=data.toString();

                // Use the data as required
                // For example:
               outFile4 << itd.toStdString()<<std::endl;
            }

            outFile4.close();
    }

}
// Double Click For Showing Profile
void MainWindow::on_lvalluser_doubleClicked(const QModelIndex &index)
{
// Check If Variable Is Ok
    if (index.isValid())
       {
           // Get the item from the index
           QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->lvalluser->model());
           QStandardItem* item = model->itemFromIndex(index);

           // Handle the double-click event for the clicked item
           if (item)
           {
               // Handle the event based on your requirements
               // For example, you can get the item text and display it
               QString itemText = item->text();
               appselectUser=itemText.toStdString();

               SelectedUsers *slf=new SelectedUsers();
               slf->show();

           }
      }
}

// Profile Image
void MainWindow::on_btnselectimage_clicked()
{
  filename = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Images (*.png *.jpg *.jpeg)");

    QPixmap newImage(filename);
    QImage image(filename);

        // Create a QGraphicsScene and set the new image as its background
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image)); // Create a QGraphicsPixmapItem
    QGraphicsScene* scene = new QGraphicsScene(ui->gwimg);

        scene->addItem(pixmapItem);

        // Set the new scene for the QGraphicsView

    ui->gwimg->setScene(scene);
    ui->gwimg->fitInView(pixmapItem, Qt::IgnoreAspectRatio);

}

// Background Image
void MainWindow::on_btnselectbgimg_clicked()
{

 bgfilename = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Images (*.png *.jpg *.jpeg)");
    QPixmap newImage(bgfilename);

        // Create a QGraphicsScene and set the new image as its background
        QGraphicsScene* scene = new QGraphicsScene(ui->gwbimg);
        scene->setBackgroundBrush(QBrush(newImage));

        // Set the new scene for the QGraphicsView
        ui->gwbimg->setScene(scene);
}


void MainWindow::on_btnapply_clicked() {

    User *_currentUser=new  User();
    _currentUser->setUsername(appcurrentUser);

    _currentUser->loadProfile();

    if (!ui->lineEdit->text().isEmpty() && ui->lineEdit->text().toStdString() ==_currentUser->getPassword()){

        QMessageBox msgBoxOne;
        msgBoxOne.setText("! Please Enter New Password");
        msgBoxOne.setWindowTitle("Warning");
        msgBoxOne.setIcon(QMessageBox::Information);
        msgBoxOne.addButton(QMessageBox::Ok);
        msgBoxOne.exec();

    } else {

        if (!ui->lineEdit->text().isEmpty() && ui->lineEdit->text().toStdString() !=_currentUser->getPassword()){

        QString st=ui->lineEdit->text();
        if (st.length() < 8) {
         QMessageBox msgBox;
         msgBox.setText("! Password Must Be At Least 8 Character");
         msgBox.setWindowTitle("Warning");
         msgBox.setIcon(QMessageBox::Information);
         msgBox.addButton(QMessageBox::Ok);
         msgBox.exec();

        } else {

         QMessageBox msgBox;
         msgBox.setText("* Password Successfuly Changed");
         msgBox.setWindowTitle("Warning");
         msgBox.setIcon(QMessageBox::Information);
         msgBox.addButton(QMessageBox::Ok);
         msgBox.exec();;

            std::ifstream inputFile(_currentUser->getUsername()+"/info.txt");
            std::vector<std::string> lines;
            std::string line;

            // Read all lines from the file
            while (std::getline(inputFile, line)) {
                lines.push_back(line);
            }

            inputFile.close();

            // Change line 2 with "bbbbbb"
            if (lines.size() >= 2) {
                lines[1] = st.toStdString();
            }

            std::ofstream outputFile(_currentUser->getUsername()+"/info.txt");

            // Write all lines back to the file
            for (const std::string& line : lines) {
                outputFile << line << std::endl;
            }

            outputFile.close();
        }
    }
}



     if (_currentUser->_type=="Anony"){
         return;
     }

    if (!filename.isEmpty()){

         _currentUser->setImg(filename.toStdString());
         QMessageBox msgBox;
         msgBox.setText("* Image Successfuly Changed");
         msgBox.setWindowTitle("Warning");
         msgBox.setIcon(QMessageBox::Information);
         msgBox.addButton(QMessageBox::Ok);
         msgBox.exec();

    }
    if (!bgfilename.isEmpty()){

         _currentUser->setBgImg(bgfilename.toStdString());
         QMessageBox msgBoxOne;
         msgBoxOne.setText("* Banner Successfuly Changed");
         msgBoxOne.setWindowTitle("Warning");
         msgBoxOne.setIcon(QMessageBox::Information);
         msgBoxOne.addButton(QMessageBox::Ok);
         msgBoxOne.exec();

    }
    if (!ui->textEdit->toPlainText().isEmpty()){
        QString st=ui->textEdit->toPlainText();
        if(_currentUser->_type=="Organisation"){
            if(st.length() >= 1110){
                QMessageBox msgBoxOne;
                msgBoxOne.setText("! BioGraphy Is More Than 1110 Character");
                msgBoxOne.setWindowTitle("Warning");
                msgBoxOne.setIcon(QMessageBox::Information);
                msgBoxOne.addButton(QMessageBox::Ok);
                msgBoxOne.exec();

                return;
            }
        }
        if (_currentUser->_type=="Personal"){

        if (st.length() >= 160) {
            QMessageBox msgBoxOne;
            msgBoxOne.setText("! BioGraphy Is More Than 160 Character");
            msgBoxOne.setWindowTitle("Warning");
            msgBoxOne.setIcon(QMessageBox::Information);
            msgBoxOne.addButton(QMessageBox::Ok);
            msgBoxOne.exec();

            return;
        }else{

            _currentUser->setBio(st.toStdString());
            ui->lblbio->setText(st);
            QMessageBox msgBoxOne;
            msgBoxOne.setText("* BioGraphy Successfuly Changed");
            msgBoxOne.setWindowTitle("Warning");
            msgBoxOne.setIcon(QMessageBox::Information);
            msgBoxOne.addButton(QMessageBox::Ok);
            msgBoxOne.exec();
        }
        }
         else {
            _currentUser->setBio(st.toStdString());
            ui->lblbio->setText(st);
            QMessageBox msgBoxOne;
            msgBoxOne.setText("* BioGraphy Successfuly Changed");
            msgBoxOne.setWindowTitle("Warning");
            msgBoxOne.setIcon(QMessageBox::Information);
            msgBoxOne.addButton(QMessageBox::Ok);
            msgBoxOne.exec();
        }
    }
}

void MainWindow::on_btblogout_clicked()
{

    MainWindow::hide();
    loginForm *lgf = new loginForm;
    lgf->show();
}

// Delete Account
void MainWindow::on_pushButton_2_clicked()
{

    User *_currentUser=new  User();
    _currentUser->setUsername(appcurrentUser);

    _currentUser->loadProfile();

    QDir dir(QString::fromStdString(_currentUser->getUsername()));
    // Get And Remove All Account Directly
    dir.removeRecursively();
    MainWindow::hide();
    loginForm *lgf = new loginForm;
    lgf->show();
}


void MainWindow::on_btnprofile_clicked()
{

    User *_currentUser=new  User();
    _currentUser->setUsername(appcurrentUser);

    _currentUser->loadProfile();
    std::ifstream file(_currentUser->getUsername()+"/following.txt");

    vector<string> followerlist;

    std::string line;
    while (std::getline(file, line)) {
        followerlist.push_back(line);
     }

    file.close();

    QStandardItemModel *model = new QStandardItemModel();


  for(string& st: followerlist){

      QStandardItem *item1 = new QStandardItem(QString::fromStdString(st));
      model->appendRow(item1);

  }
      ui->lvfollowing->setModel(model);
}
