#ifndef PERSONALUSER_H
#define PERSONALUSER_H

#include "user.h"
#include "QDir"

class PersonalUser: public User
{

private:
    std::string company;

public:
    PersonalUser();
    void setCompany(string _company);
    std::string getCompany();

    std::string registerUsers();

};

#endif // PERSONALUSER_H
