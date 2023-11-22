#include "LoginPage.h"
#include <QMessageBox>
LoginPage::LoginPage(QWidget* parent) : QWidget(parent) 
{
    setWindowTitle("Login Page");

    QVBoxLayout* layout = new QVBoxLayout(this);
    database.Connection();
    usernameEdit = new QLineEdit(this);
    layout->addWidget(usernameEdit);

    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordEdit);

    QPushButton* loginButton = new QPushButton("Login", this);
    layout->addWidget(loginButton);


    connect(loginButton, &QPushButton::clicked, this, &LoginPage::onLoginClicked);
}

void LoginPage::onLoginClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    bool ok = database.searchUser(username.toStdString());
    if (ok) {
        QMessageBox::information(this, "Login", "Logare reușită");
        nextFrame = 1;
    }
    else {
        QMessageBox::warning(this, "Login", "Logare eșuată");
        nextFrame = 0;
    }
}
