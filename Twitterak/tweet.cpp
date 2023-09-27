#include "tweet.h"

Tweet::Tweet() {}

Tweet::Tweet(string _id, string _text, int _textLen){

    id=_id;
    text=_text;
    textLen=_textLen;
}

void Tweet::setId(string _id){

    id=_id;
}

string Tweet::getId(){
    return id;
}

void Tweet::setText(string _text){
    text=_text;
}

string Tweet::getText(){

    return text;
}

void Tweet::setTextLen(int _textLen){
    textLen=_textLen;
}

int Tweet::getTextLen(){
    return  textLen;
}

void Tweet::setComment(string _text){
    comment.push_back(_text);
}

vector<string> Tweet::getComment(){
    return comment;
}


void Tweet::setLike(string _text){
    like.push_back(_text);
}

vector<string> Tweet::getLike(){
    return like;
}

void Tweet::setDislike(string _text){
     dislike.push_back(_text);
}

vector<string> Tweet::getDislike(){
    return dislike;
}

QString Tweet::generateUniqueID() {
    QByteArray byteArray = QUuid::createUuid().toString().toUtf8();
    QString id = byteArray.mid(1, 4); // Extract the first 4 characters from the generated UUID
    id.remove('-'); // Remove the hyphens in the generated ID
    setId(id.toStdString());
    return id;
}
