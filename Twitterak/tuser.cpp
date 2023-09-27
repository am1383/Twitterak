#include "tuser.h"
#include "tweet.h"

TUser::TUser(){}

void TUser::setUsername(std::string _username){
    username=_username;
}
string TUser::getUsername(){

    return username;
}

void TUser::setPassword(string _password){
    password=_password;
}

string TUser::getPassword(){
    return password;
}

void TUser::setMobile(string _mobile){
    mobile=_mobile;
}
string TUser::getMobile(){
    return mobile;
}

void TUser::addTweet(Tweet _tweet){}

void TUser::getTweet(){}

void TUser::addfollowing(string _text){}

void TUser::getFollowing(){}

bool login(string _user,string _password){
    return true;
}

bool logout(string _user){
    return true;
}

bool removeTweet(string _text){
    return true;
}
bool addMention(TUser user){
    return true;
}
