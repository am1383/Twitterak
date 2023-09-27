class User;

#include "personaluser.h"
#include "orguser.h"
#include "user.h"
#include <regex>
#include <iostream>
#include <fstream>

PersonalUser::PersonalUser() {}

string PersonalUser::registerUsers(){

    if (QDir(QString::fromStdString(getUsername())).exists()){
        QString currentDir = QDir::currentPath();

        return "! This User Name Is Not Available Please Try Again";

   }else{

    }

    if (!getUsername().empty()) {

        } else {
        return "! Please Fill The UserName";
        }


    if (!getCountry().empty()) {

        } else {
        return "! Please Fill The Country";
        }


    if (!getName().empty()) {

        } else {
        return "! Please Fill The Name";
        }

    if (!getPassword().empty()) {

        } else {
        return "! Please Fill The Password";
        }

    string userName = getUsername();
    if (userName.length() < 5) {

       return "! UserName Must Be At Least 5 Character";
       }

    if (userName == "Login" || userName == "Register" || userName == "Exit") {
        return "! This User Name Is CommandLine You Please Try Again";
    }


   std::regex pattern("^\\+\\d{1,3}-\\d{5,15}$"); // Country code followed by hyphen and digits // Regular expression to match country code

   if (regex_match(getMobile(), pattern)) {

       } else {
       return "! Invalid Mobile! Mobile Number Must Like +98-123456789";
       }



           string pass=getPassword();
            regex passwordPattern("^(?=.*[a-zA-Z])(?=.*[0-9]).{8,}$");
            if (regex_match(pass, passwordPattern)) {

                } else {
                return "! Invalid Password! Password Must Contain 8 Char And Number";
                }



            QDir().mkdir(QString::fromStdString(getUsername()));

            std::ofstream outFile(getUsername()+"/info.txt");
            if (outFile.is_open()) {
                    // Writing multiple lines to the file


                    outFile << getUsername() << std::endl;
                    outFile << getPassword() << std::endl;
                    outFile << getMobile() << std::endl;
                    outFile << getCountry() << std::endl;
                    outFile << getName() << std::endl;
                    outFile << getCompany()<<std::endl;
                    outFile << "Personal" << std::endl;

                    outFile.close();

                } else {
                    return "! Failed To Open The File / Please Contact Developrs";
                }

            std::ofstream outFile2(getUsername()+"/bio.txt");
            if (outFile2.is_open()) {

                    outFile2 << "BioGraphy Test (Limit 160)" << std::endl;
                    outFile2.close();

                } else {
                    return "! Invalid User Name Or Passwprd Please Try Again" ;
                }
            std::ofstream outFile3(getUsername()+"/following.txt");
            if (outFile3.is_open()) {


                    outFile3.close();

                } else {
                    return "! Invalid User Name Or Passwprd Please Try Again" ;
                }

            std::ofstream outFile4(getUsername()+"/tweet.txt");
            if (outFile4.is_open()) {


                    outFile4.close();

                } else {
                    return "! Invalid User Name Or Passwprd Please Try Again" ;
                }


   return "* Retgister Was Successful";
}
void PersonalUser::setCompany(string _company){
    company=_company;

}
std::string PersonalUser::getCompany(){

    return  company;

}
