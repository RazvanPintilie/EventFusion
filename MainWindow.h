#ifndef EXITPAGE_H
#define EXITPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include "LoginPage.h"
#include "SingupPage.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private slots:
    void onLoginClicked();
    void onSignUpClicked();

private:
    QStackedWidget* stackedWidget;

    QPushButton* loginButton;
    QPushButton* signUpButton;

    // buttons
    LoginPage* loginPage;
    SignUpPage* signUpPage;
    QPushButton* exitButton;
};


#endif // EXITPAGE_H
