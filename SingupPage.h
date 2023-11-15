#pragma once
#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class SignUpPage : public QWidget {
    Q_OBJECT

public:
    SignUpPage(QWidget* parent = nullptr);

private slots:
    void onSignUpClicked();

private:
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
};

#endif // SIGNUPPAGE_H
