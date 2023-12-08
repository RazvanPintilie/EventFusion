#include "MainWindow.h"
#include <QApplication>
#include <iostream>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Event Fusion");
    resize(900, 600);

    stackedWidget = new QStackedWidget(this);

    // Adăugare pagini (butoanele și paginile de login și înregistrare) în QStackedWidget
    QWidget* buttonWidget = new QWidget;
    QVBoxLayout* buttonLayout = new QVBoxLayout(buttonWidget);
    loginButton = new QPushButton("Login", buttonWidget);
    signUpButton = new QPushButton("Sign Up", buttonWidget);
    exitButton = new QPushButton("Exit", this);
    //backButton = new QPushButton("Back", this);
    exitButton->setGeometry(720, 520, 100, 50);
    //backButton->setGeometry(100, 500, 100, 50);
    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(signUpButton);
    buttonWidget->setLayout(buttonLayout);

    loginPage = new LoginPage;
    signUpPage = new SignUpPage;
    workPage = new WorkPage;

    stackedWidget->addWidget(buttonWidget); // Adăugarea widget-ului cu butoane în QStackedWidget
    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(signUpPage);
    stackedWidget->addWidget(workPage);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
    setLayout(mainLayout);

    // Conectarea butoanelor pentru a schimba vizualizarea în funcție de ce buton este apăsat
    connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(signUpButton, &QPushButton::clicked, this, &MainWindow::onSignUpClicked);
   // connect(backButton, &QPushButton::clicked, this, &MainWindow::onBackClicked);
    connect(loginPage, &LoginPage::loginSuccess, this, &MainWindow::switchToWorkPage);
    connect(signUpPage, &SignUpPage::signupSuccess, this, &MainWindow::onLoginClicked);
    
}

void MainWindow::onLoginClicked()
{
    stackedWidget->setCurrentIndex(1); // Schimbarea la pagina de login (indexul 1 în QStackedWidget)
}

void MainWindow::onSignUpClicked()
{
    stackedWidget->setCurrentIndex(2); // Schimbarea la pagina de înregistrare (indexul 2 în QStackedWidget)
}
void MainWindow::onBackClicked()
{
    stackedWidget->setCurrentIndex(0); // Schimbarea la pagina de înregistrare (indexul 2 în QStackedWidget)
}

void MainWindow::switchToWorkPage()
{
    stackedWidget->setCurrentIndex(3); // Schimbarea la pagina de înregistrare (indexul 2 în QStackedWidget)
}
