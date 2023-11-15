#include "SingupPage.h"
#include <QMessageBox>

SignUpPage::SignUpPage(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Sign Up Page");

    QVBoxLayout* layout = new QVBoxLayout(this);

    usernameEdit = new QLineEdit(this);
    layout->addWidget(usernameEdit);

    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordEdit);

    QPushButton* signUpButton = new QPushButton("Sign Up", this);
    layout->addWidget(signUpButton);

    connect(signUpButton, &QPushButton::clicked, this, &SignUpPage::onSignUpClicked);
}

void SignUpPage::onSignUpClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Add sign-up logic here
    // For now, just show a message box
    QMessageBox::information(this, "Sign Up", "Username: " + username + "\nPassword: " + password);
}
