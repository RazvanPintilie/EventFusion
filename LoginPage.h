#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include "DataBase.h"

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    LoginPage(QWidget* parent = nullptr);
private slots:
    void onLoginClicked();
signals:
    void loginSuccess();
private:
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    QLabel* usernameLabel;
    QLabel* passwordLabel;
    Database database;

};

#endif // LOGINPAGE_H

