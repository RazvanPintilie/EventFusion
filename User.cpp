#include "User.h"

User& User::getInstance() {
    static User instance;
    return instance;
}

void User::setUsername(const QString& username) {
    this->username = username;
}

QString User::getUsername(){
    return this->username;
}