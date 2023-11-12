#include "loginform.h"
#include <QVBoxLayout>
#include <QMessageBox>

LoginForm::LoginForm(QWidget* parent)
    : QWidget(parent)
{
    loginButton = new QPushButton("Login");
    loginButton->setFixedSize(300, 50);
    usernameInput = new QLineEdit();
    passwordInput = new QLineEdit();
    passwordInput->setEchoMode(QLineEdit::Password);
    usernameInput->setPlaceholderText("username");
    passwordInput->setPlaceholderText("password");
    connect(loginButton, &QPushButton::clicked, this, &LoginForm::onLoginButtonClicked);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);
}

void LoginForm::onLoginButtonClicked()
{
    QString username = usernameInput->text();
    QString password = passwordInput->text();
    if (username == "admin" && password == "parola") {
        QMessageBox::information(this, "Login", "Logare reușită!");
        isConnected = true;
    }
    else {
        QMessageBox::critical(this, "Login", "Logare eșuată. Verificați numele de utilizator și parola.");
    }
}
bool LoginForm::getConnected() {
    return isConnected;
}
LoginForm::~LoginForm() {

}