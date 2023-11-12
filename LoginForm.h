#pragma once
#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    LoginForm(QWidget* parent = nullptr);
    bool getConnected();
    ~LoginForm();
private:
    bool isConnected;
    QPushButton* loginButton;
    QLineEdit* usernameInput;
    QLineEdit* passwordInput;

private slots:
    void onLoginButtonClicked();

};

#endif