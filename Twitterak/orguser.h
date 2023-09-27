#ifndef ORGUSER_H
#define ORGUSER_H

#include "user.h"
#include "QDir"

class OrgUser: public User
{

private:
    std::string boss;

public:
    OrgUser();
    void setBoss(string _boss);
    std::string getBoss();
    std::string registerUsers();
};

#endif // ORGUSER_H
