class Tweet;

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "tweet.h"

class User
{

private:
    std::string name;
    std::string username;
    std::string password;
    std::string mobile;

    std::vector<std::string> following;
    std::vector<std::string> followers;
    std::string country;
    std::string link;
    std::string birthday;
    std::string bosscompany;
    std::string headercolor;

    std::string bio;
    std::string bgimg;
    std::string img;
    std::vector<std::string> hashtag;
    std::vector<Tweet> tweets;

public:
    User();
    string _type;
    void loadProfile();
    void setName(std::string name);
    string getName();

    void setCountry(std::string _country);
    string getCountry();

    void setUsername(std::string _username);
    string getUsername();

    void setPassword(string _password);
    string getPassword();

    void setMobile(string _mobile);
    string getMobile();

    void addTweet(Tweet _tweet);
    std::vector<Tweet> getTweet();

    void addfollowing(string _text);
    vector<string>  getFollowing();

    void addfollowers(string _text);
    void getFollowers();

    string login(string _user,string _password);
    bool logout(string _user);

    std::string getBirthday();
    std::string getHeadercolor();

    std::string getBio();
    std::string getBgImg();
    std::string getImg();

    void setBirthday(string birthday);
    void setHeadercolor(string headercolor);

    void setBio(string bio);
    void setBgImg(string bgimg);
    void setImg(string img);

    int addMention(string _tweet,string _mention);
    vector<string> getMention(string _tweet);
    int addLike(string _tweet);
    int addDislike(string _tweet);

    std::vector<std::string> splitString(const std::string& input, char delimiter);
};

#endif // USER_H
