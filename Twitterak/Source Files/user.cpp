#include "user.h"
#include "tweet.h"
#include "fstream"

User::User(){}

void User::setUsername(std::string _username){
    username=_username;
}

string User::getUsername(){
    return username;
}

void User::setName(std::string _username){
    name=_username;
}

string User::getName(){
    return name;
}

void User::setCountry(std::string _country){
    country=_country;
}

string User::getCountry(){

    return country;
}

void User::setPassword(string _password){
    password=_password;
}

string User::getPassword(){
    return password;
}

void User::setMobile(string _mobile){
    mobile=_mobile;
}

string User::getMobile(){
    return mobile;
}

void User::addTweet(Tweet _tweet){}

std::vector<Tweet> User::getTweet(){
    return tweets;
}

void User::addfollowing(string _text){}

vector<string> User::getFollowing(){
    return following;
}

std::string User::getBirthday(){
    return birthday;
}

std::string User::getHeadercolor(){
    return headercolor;
};

std::string User::getBio(){
// Limited BioGrahpy
    return bio.substr(0, 1100);
};

std::string User::getBgImg(){

    bgimg="";
    std::ifstream file4(getUsername()+"/bgimg.txt");  // Open the file for reading
    if (file4.is_open()) {
        std::string line;
           while (std::getline(file4, line)) {
               bgimg=line;
           }
           file4.close();

           // Print the lines

       }
    return bgimg;
};
std::string User::getImg(){

    img="";
    std::ifstream file4(getUsername()+"/img.txt");  // Open The File For Reading
    if (file4.is_open()) {
        std::string line;
           while (std::getline(file4, line)) {
               img=line;
           }
           file4.close();

           // Print the lines
       }

    return img;
};

void User::setBirthday(string _birthday){
     birthday=_birthday;
};
void User::setHeadercolor(string _headercolor){
     headercolor=_headercolor;
};


void User::setBio(string _bio){

    std::ofstream file(getUsername()+"/bio.txt");
    if (file.is_open()){

        file<<_bio;
        file.close();

    }

    bio=_bio;

}
void User::setBgImg(string _bgimg){

     std::ofstream file(getUsername()+"/bgimg.txt");
     if (file.is_open()){

         file<<_bgimg;
         file.close();
     }

     bgimg=_bgimg;
}
void User::setImg(string _img){


    std::ofstream file(getUsername()+"/img.txt");
    if (file.is_open()){

        file<<_img;
        file.close();

    }
    img=_img;
}

string User::login(string _user,string _password){

   std::ifstream file(_user+"/info.txt");  // Open the file for reading
   int i=0;
   string username;
   string password;
       if (file.is_open()) {  // Check if the file is successfully opened
           std::string line;
           while (std::getline(file, line)) {  // Read each line of the file
             //  std::cout << line << std::endl;  // Print the line
               if (i==0){

                   username=line;
               }
               else if (i==1){
                   password=line;
               }else{

                   break;
               }
               i++;
           }

           file.close();  // Close The File
       } else {
           return  "! Invalid User Name Or Password Please Try Again";
       }

       if (username==_user && password==_password){

           return "* Register Was Successful";
       }else{

           return "! Invalid User Name Or Password Please Try Again";
       }

    return "* Register Was Successful";
}
bool User::logout(string _user){

    return true;
}

int User::addLike(string _tweet){

   int like=1;
   string l;
   char delimiter = '-';

    std::vector<std::string> splitValues = splitString(_tweet,delimiter);
    std::ifstream  file(splitValues[0]+"like.txt"); // Create an output file stream
   if (file.is_open()) {
        std::string line;
           while (std::getline(file, line)) {
               l=line;
           }
           file.close();
           like=stoi(l);
           like=like+1;

   }

       std::ofstream  file2(splitValues[0]+"like.txt"); // Create an output file stream
      if (file2.is_open()) {
           file2<<like;
              file2.close();
      }

return like;

}

int User::addDislike(string _tweet){


    int like=0;
    string l;
    char delimiter = '-';

     std::vector<std::string> splitValues = splitString(_tweet,delimiter);
     std::ifstream  file(splitValues[0]+"like.txt"); // Create an output file stream
     if (file.is_open()) {
         std::string line;
            while (std::getline(file, line)) {
                l=line;
            }
            file.close();
           like=stoi(l);
           like=like-1;
           if (like<0){like=0;}

    }

        std::ofstream  file2(splitValues[0]+"like.txt"); // Create an output file stream
       if (file2.is_open()) {
            file2<<like;
            file2.close();
       }


    return like;
}

void User::loadProfile(){

           std::ifstream file(getUsername()+"/info.txt");  // Open the file for reading
           int i=0;
           string username;
           string password;
           string mobile;
           string country;
           string name;
           string type_;
           string bosscompany_;
           string bio;
           vector <string> _following;
               if (file.is_open()) {  // Check if the file is successfully opened
                   std::string line;
                   while (std::getline(file, line)) {  // Read each line of the file
                   // Print the line
                       if (i==0){

                           username=line;
                       }
                       else if (i==1){
                           password=line;
                       }
                       else if (i==2){
                           mobile=line;
                       }
                       else if (i==3){
                           country=line;
                       }
                       else if (i==4){
                           name=line;
                       }

                       else if (i==5){
                           bosscompany_=line;
                       }
                       else if (i==6){
                           type_=line;
                       }
                       else{

                           break;
                       }
                       i++;
                   }

                   file.close();  // Close the file
               } else {
                   return;
            }

         std::ifstream file2(getUsername()+"/bio.txt");  // Open the file for reading
         if (file2.is_open()) {  // Check if the file is successfully opened
             std::string line;
             while (std::getline(file2, line)) {  // Read each line of the file
               // Print the line
                 bio=line;
             }

             file2.close();  // Close the file
         } else {
             return;
         }

          std::ifstream file3(getUsername()+"/following.txt");  // Open the file for reading
         if (file3.is_open()) {
              std::string line;
                 while (std::getline(file3, line)) {
                     _following.push_back(line);
                 }
                 file3.close();

                 // Print the lines

             }

         std::ifstream file4(getUsername()+"/tweet.txt");  // Open the file for reading
        if (file4.is_open()) {
             std::string line;
                while (std::getline(file4, line)) {
                    Tweet tw;

                    char delimiter = '-';
                    std::vector<std::string> splitValues = splitString(line,delimiter);

                    tw.setId(splitValues[0]);
                    tw.setText(splitValues[1]);


                    tweets.push_back(tw);
                }
                file4.close();

                // Print the lines

            }

                    setBio(bio);

                    setUsername(username);
                    setPassword(password);
                    setMobile(mobile);
                    setCountry(country);
                    setName(name);
                    _type=type_;
                    bosscompany=bosscompany_;

                    following=_following;
        }

//split tweet to tweet id and tweet body
std::vector<std::string> User::splitString(const std::string& input, char delimiter) {

            std::vector<std::string> result;
            std::string currString = "";

            for (char ch : input) {
                if (ch != delimiter) {
                    currString += ch;
                } else {
                    if (!currString.empty()) {
                        result.push_back(currString);
                        currString = "";
                    }
                }
            }

            if (!currString.empty()) {
                result.push_back(currString);
            }

            return result;
}

vector<string> User::getMention(string _tweet){

    vector<string> _mention;
    char delimiter = '-';

    std::vector<std::string> splitValues = splitString(_tweet,delimiter);
    std::ifstream file(splitValues[0]+".txt"); // Create an output file stream
   if (file.is_open()) {
        std::string line;
           while (std::getline(file, line)) {
               _mention.push_back(line);
           }
           file.close();

           // Print the lines

       }


   return _mention;
}

int User::addMention(string _tweet,string _mention){

     char delimiter = '-';
     std::vector<std::string> splitValues = splitString(_tweet,delimiter);
     std::ofstream file(splitValues[0]+".txt", std::ios::app); // Create an output file stream

 // Writing to the file
      file <<getUsername()+"->"+ _mention << std::endl;

 // Close the file stream
      file.close();

      return 1;
}
