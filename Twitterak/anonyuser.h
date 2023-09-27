#ifndef ANONYUSER_H
#define ANONYUSER_H

#include "user.h"
#include "QDir"

class AnonyUser: public User
{

public:
    AnonyUser();
    std::string registerUsers();

};

#endif // ANONYUSER_H
