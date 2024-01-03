#ifndef TWEET_H
#define TWEET_H

#include <string>
#include <vector>
#include <tuser.h>
// Header File Use For Generating Unique ID
#include <quuid.h>

using namespace std;

class Tweet
{

private:

    string id;
    string text;
    int textLen;
    vector<string> comment;
    vector<string> like;
    vector<string> dislike;

public:
    Tweet();
    Tweet(string id,
    string text,
    int textLen);

    void setId(string _id);
    string getId();

    void setText(string _text);
    string getText();

    void setTextLen(int _textLen);
    int getTextLen();

    void setComment(string _text);
    vector<string> getComment();

    void setLike(string _text);
    vector<string> getLike();

    void setDislike(string _text);
    vector<string> getDislike();

    QString generateUniqueID();

};

#endif // TWEET_H
