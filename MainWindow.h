#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void switchToWorkPage(bool newProjec);
    void onLoginSuccessWithOption(bool isNewProject);
private:
    QStackedWidget* stackedWidget;

    QPushButton* loginButton;
    QPushButton* signUpButton;
    
    LoginPage* loginPage;
    SignUpPage* signUpPage;
    QPushButton* exitButton;
    QPushButton* backButton;
    WorkPage* workPage;
};


#endif // MAINWINDOW_H
