#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    static User& getInstance();

    void setUsername(const QString& username);
    QString getUsername();

private:
    User() {} // Constructor privat pentru singleton

    QString username;
};

#endif