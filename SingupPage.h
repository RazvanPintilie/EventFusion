#pragma once
#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include "DataBase.h"
class SignUpPage : public QWidget 
{
    Q_OBJECT

public:
    SignUpPage(QWidget* parent = nullptr);

private slots:
    void onSignUpClicked();
signals:
    void signupSuccess();

private:
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    Database database;
};

#endif // SIGNUPPAGE_H
