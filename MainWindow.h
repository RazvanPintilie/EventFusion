#ifndef EXITPAGE_H
#define EXITPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include "LoginPage.h"
#include "SingupPage.h"
#include "WorkPage.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
private slots:
    void onLoginClicked();
    void onSignUpClicked();
    void onBackClicked();
    void switchToWorkPage();

private:
    QStackedWidget* stackedWidget;

    QPushButton* loginButton;
    QPushButton* signUpButton;
    

    // buttons
    LoginPage* loginPage;
    SignUpPage* signUpPage;
    QPushButton* exitButton;
    QPushButton* backButton;
    WorkPage* workPage;
};


#endif // EXITPAGE_H
