#include "selectedusers.h"
#include "ui_selectedusers.h"
#include "gl.h"
#include "QStandardItem"
#include "QStringListModel"
#include "fstream"
#include "QMessageBox"
#include "QGraphicsPixmapItem"

string selectedtweet="";

SelectedUsers::SelectedUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectedUsers)
{

    selectedtweet="";
    ui->setupUi(this);

    User *_currentUser=new  User();
    _currentUser->setUsername(appselectUser);

    _currentUser->loadProfile();

    ui->lblbio->setText(QString::fromStdString(_currentUser->getBio()));
    ui->lblname->setText(QString::fromStdString(_currentUser->getName()));
    ui->lblfollowingcount->setText(QString::fromStdString(to_string(_currentUser->getFollowing().size())));


QStandardItemModel *_model = new QStandardItemModel();
    for (Tweet& tw : _currentUser->getTweet()) {

           Tweet tww;

           string td=tw.getId()+'-'+tw.getText();


           QStandardItem *item = new QStandardItem(QString::fromStdString(td));
           _model->appendRow(item);
            ui->lvalltweet->setModel(_model);
       }

    QPixmap newImage(QString::fromStdString(_currentUser->getImg()));
    QImage image(QString::fromStdString(_currentUser->getImg()));

        // Create a QGraphicsScene and set the new image as its background
    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image)); // Create a QGraphicsPixmapItem
    QGraphicsScene* scene = new QGraphicsScene(ui->graphicsView_2);

        scene->addItem(pixmapItem);

        // Set the new scene for the QGraphicsView

        ui->graphicsView_2->setScene(scene);
        ui->graphicsView_2->fitInView(pixmapItem, Qt::IgnoreAspectRatio);


        if (_currentUser->_type=="Anony"){

            QPixmap newImage(QString::fromStdString(_currentUser->getImg()));
            QImage image(QString::fromStdString("c:/anony/anony.jpg"));

                // Create a QGraphicsScene and set the new image as its background
            QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image)); // Create a QGraphicsPixmapItem
            QGraphicsScene* scene = new QGraphicsScene(ui->graphicsView_2);

                scene->addItem(pixmapItem);

                // Set the new scene for the QGraphicsView

                ui->graphicsView_2->setScene(scene);
                ui->graphicsView_2->fitInView(pixmapItem, Qt::IgnoreAspectRatio);

        }

           QPixmap newImage1(QString::fromStdString(_currentUser->getBgImg()));

               // Create a QGraphicsScene and set the new image as its background
               QGraphicsScene* scene1 = new QGraphicsScene(ui->graphicsView);
               scene1->setBackgroundBrush(QBrush(newImage1));

               // Set the new scene for the QGraphicsView
               ui->graphicsView->setScene(scene1);

}

SelectedUsers::~SelectedUsers()
{
    delete ui;
}
// Show Tweets In Profile
void SelectedUsers::on_lvalltweet_clicked(const QModelIndex &index)
{


    if (index.isValid())
       {
           // Get the item from the index
           QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->lvalltweet->model());
           QStandardItem* item = model->itemFromIndex(index);

           // Handle the double-click event for the clicked item
           if (item)
           {
               // Handle the event based on your requirements
               // For example, you can get the item text and display it
               QString itemText = item->text();
               string itemTextstr=itemText.toStdString();
                selectedtweet=itemTextstr;


           }
       }
// Show Mention After Comment
    User *_currentUser=new  User();
    _currentUser->setUsername(appcurrentUser);
    _currentUser->loadProfile();
    vector<string> _men= _currentUser->getMention(selectedtweet);
      QStandardItemModel *model = new QStandardItemModel();

      for (string& st:_men){

          QStandardItem *item1 = new QStandardItem(QString::fromStdString(st));
          model->appendRow(item1);

      }

      ui->listView->setModel(model);
}

// Add Comment
void SelectedUsers::on_pushButton_clicked()
{

    if(selectedtweet==""){


        return;
    }

    if (ui->txtcomment->text().isEmpty()){

        return;

    }

    User *_currentUser=new  User();
    _currentUser->setUsername(appcurrentUser);
    _currentUser->loadProfile();
    _currentUser->addMention(selectedtweet,ui->txtcomment->text().toStdString());
    ui->txtcomment->setText("");

    vector<string> _men= _currentUser->getMention(selectedtweet);
    QStandardItemModel *model = new QStandardItemModel();

    for (string& st:_men){

        QStandardItem *item1 = new QStandardItem(QString::fromStdString(st));
        model->appendRow(item1);

    }

    ui->listView->setModel(model);

}


void SelectedUsers::on_btnlike_clicked()
{
    if(selectedtweet==""){

        return;
    }
   // if (appislike=="1"){return;}
        User *_currentUser=new  User();
        _currentUser->setUsername(appcurrentUser);
        _currentUser->loadProfile();
        int sumlike= _currentUser->addLike(selectedtweet);
        if (sumlike>1){
            sumlike=1;
        }
        ui->lbllike->setText(QString::fromStdString(to_string(sumlike)));
        appislike="1";
}


void SelectedUsers::on_btndislike_clicked()
{
    if (selectedtweet==""){

        return;
    }
   // if (appdislike=="1"){return;}
        User *_currentUser=new  User();
        _currentUser->setUsername(appcurrentUser);
        _currentUser->loadProfile();
        int sumlike= _currentUser->addDislike(selectedtweet);
        if (sumlike>1){
            sumlike=1;
        }
        ui->lbllike->setText(QString::fromStdString(to_string(sumlike)));
        appdislike="1";
}


bool isStringInFile(const std::string& filename, const std::string& searchStr) {
    std::ifstream file(filename); // Open the file for reading
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line == searchStr) {
                file.close(); // Close the file
                return true;
            }
        }
        file.close(); // Close the file
    }

    return false;
}
// Follow System
void SelectedUsers::on_btnfollow_clicked()
{
    User *_currentUser=new  User();
    _currentUser->setUsername(appselectUser);
    _currentUser->loadProfile();
    if(_currentUser->getUsername() == appcurrentUser){
            QMessageBox msgBox;
            msgBox.setText(QString::fromStdString("! You Can't Follow Yourself"));
            msgBox.setWindowTitle("Warning");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
            return;
}
    if(_currentUser->_type=="Anony"){

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("! Anony user Can Not Be Follow"));
        msgBox.setWindowTitle("Warning");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return;

    }

    if (isStringInFile(appcurrentUser+"/following.txt",appselectUser)){

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("! You Already Following This Account"));
        msgBox.setWindowTitle("Warning");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();

        return;
    }

    std::ofstream outputFile;
       outputFile.open(appcurrentUser+"/following.txt", std::ios::app); // Open the file in append mode

       if (outputFile.is_open()) {
           outputFile << appselectUser<<endl;
           outputFile.close();
       }

       QMessageBox msgBox;
       msgBox.setText(QString::fromStdString("* Account Followed"));
       msgBox.setWindowTitle("Warning");
       msgBox.setIcon(QMessageBox::Information);
       msgBox.addButton(QMessageBox::Ok);
       msgBox.exec();

       std::ofstream outputFile2;
          outputFile2.open("followers.txt", std::ios::app); // Open the file in append mode

          if (outputFile2.is_open()) {
              outputFile2 <<appcurrentUser+"-"+appselectUser<<endl;
              outputFile2.close();

          }

}

    void deleteLineFromFile(const std::string& filename, const std::string& lineToDelete) {
    // Create input and output file streams
    std::ifstream inputFile(filename);
    std::ofstream tempFile("temp.txt");

    // Read file line by line and copy to temp file, excluding the specified line
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line != lineToDelete) {
            tempFile << line << std::endl;
        }
    }

    // Close file streams
    inputFile.close();
    tempFile.close();

    // Delete the original file
    std::remove(filename.c_str());

    // Rename the temp file to the original file name
    std::rename("temp.txt", filename.c_str());
}

void SelectedUsers::on_btnunfollow_clicked()
{

    User *_currentUser=new  User();
    _currentUser->setUsername(appselectUser);
    _currentUser->loadProfile();


    if(_currentUser->_type=="Anony"){

        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("! Anony User Can Not Be Follow"));
        msgBox.setWindowTitle("Warning");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }

    if(_currentUser->getUsername() == appcurrentUser){
            QMessageBox msgBox;
            msgBox.setText(QString::fromStdString("! You Can't UnFollow Yourself"));
            msgBox.setWindowTitle("Warning");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.addButton(QMessageBox::Ok);
            msgBox.exec();
            return;
}

    deleteLineFromFile(appcurrentUser+"/following.txt",appselectUser);
    deleteLineFromFile("followers.txt",appcurrentUser+"-"+appselectUser);
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString("* Account UnFollowed"));
    msgBox.setWindowTitle("Warning");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.addButton(QMessageBox::Ok);
    msgBox.exec();

}
