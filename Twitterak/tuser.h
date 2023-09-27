class Tweet;

#ifndef TUSER_H
#define TUSER_H

#include <string>
#include <vector>
#include "tweet.h"

using namespace std;

class TUser
{

private:
    std::string username;
    std::string password;
    std::string mobile;
    std::vector<Tweet> tweets;
    std::vector<std::string> following;
    std::vector<std::string> followers;

    std::string bio;;
    std::string bgimg;
    std::string img;

public:
    TUser();
    void setUsername(std::string _username);
    string getUsername();

    void setPassword(string _password);
    string getPassword();

    void setMobile(string _mobile);
    string getMobile();

    void addTweet(Tweet _tweet);
    void getTweet();

    void addfollowing(string _text);
    void getFollowing();

    void addfollowers(string _text);
    void getFollowers();

    bool login(string _user,string _password);
    bool logout(string _user);

    int  registerUser();

    bool removeTweet(Tweet _tweet);
    bool addMention(Tweet _tweet);
    bool addLike(Tweet _tweet);
    bool addDislike(Tweet _tweet);

};

#endif // TUSER_H
