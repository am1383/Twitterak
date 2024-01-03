#include "anonyuser.h"

class User;

#include "personaluser.h"
#include "orguser.h"
#include "user.h"
// A Header File For Choosing Specefic Characters
#include <regex>
#include <iostream>
#include <fstream>

AnonyUser::AnonyUser(){}

string AnonyUser::registerUsers(){
// Directory
    if (QDir(QString::fromStdString(getUsername())).exists()){
        QString currentDir = QDir::currentPath();

        return "! This User Name Is Not Available Please Try Again";

   } else{}

    if (!getPassword().empty()) {

        } else {
        return "! Please Fill The Password";
        }

    string userName = getUsername();
    if (userName.length() < 5) {

       return "! User Name Must Be At Least 5 Character";
       }

    if (userName == "Login" || userName == "Register" || userName == "Exit")
    {
        return "! This User Name Is CommandLine You Please Try Again";
    }

           string pass=getPassword();
            regex passwordPattern("^(?=.*[a-zA-Z])(?=.*[0-9]).{8,}$");
            if (regex_match(pass, passwordPattern)) {

                } else {
                return "Invalid Password! Password Must Contain 8 Char And Number";
                }


QDir().mkdir(QString::fromStdString(getUsername()));
            std::ofstream outFile(getUsername()+"/info.txt");
            if (outFile.is_open()) {
                    // Writing multiple lines to the file


                    outFile << getUsername() << std::endl;
                    outFile << getPassword() << std::endl;
                    outFile << "" << std::endl;
                    outFile << "" << std::endl;
                    outFile << "Anonymouse User" << std::endl;
                    outFile << "" << std::endl;
                    outFile << "Anony" << std::endl;


                    outFile.close();

                } else {
                    return "! Invalid User Name Or Password Please Try Again";
                }

            std::ofstream outFile2(getUsername()+"/bio.txt");
            if (outFile2.is_open()) {

                    outFile2 << "Anonymouse User Can't Set BioGraphy" << std::endl;
                    outFile2.close();

                } else {
                    return "! Invalid User Name Or Password Please Try Again";
                }

            std::ofstream outFile3(getUsername()+"/following.txt");
            if (outFile3.is_open()) {

                    outFile3.close();

                } else {
                    return "! Invalid User Name Or Password Please Try Again";
                }

            std::ofstream outFile4(getUsername()+"/tweet.txt");
            if (outFile4.is_open()) {

                    outFile4.close();

                } else {
                    return "! Invalid User Name Or Password Please Try Again";
                }

   return "* Register Was Successful";
}
