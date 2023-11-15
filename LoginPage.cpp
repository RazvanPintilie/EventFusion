#include "LoginPage.h"
#include <QMessageBox>

LoginPage::LoginPage(QWidget* parent) : QWidget(parent) 
{
    setWindowTitle("Login Page");

    QVBoxLayout* layout = new QVBoxLayout(this);

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

    // Add login logic here
    // For now, just show a message box
    QMessageBox::information(this, "Login", "Username: " + username + "\nPassword: " + password);
}
