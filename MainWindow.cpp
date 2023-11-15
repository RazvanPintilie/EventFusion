#include "MainWindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Event Fusion");
    resize(900, 600);

    stackedWidget = new QStackedWidget(this);

    exitButton = new QPushButton("Exit", this);
    loginButton = new QPushButton("Login", this);
    signUpButton = new QPushButton("Sign Up", this);

    loginPage = new LoginPage;
    signUpPage = new SignUpPage;

    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(signUpPage);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(loginButton);
    layout->addWidget(signUpButton);
    layout->addWidget(exitButton);

    exitButton->setGeometry(700, 500, 100, 30);

    connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(signUpButton, &QPushButton::clicked, this, &MainWindow::onSignUpClicked);
}

void MainWindow::onLoginClicked()
{
    stackedWidget->setCurrentWidget(loginPage);
}

void MainWindow::onSignUpClicked()
{
    stackedWidget->setCurrentWidget(signUpPage);
}
