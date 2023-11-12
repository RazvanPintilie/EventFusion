#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include "loginform.h"
#include <qlayout.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Login Example");
    window.setFixedSize(1000, 400);
    QWidget buttonsPage;
    LoginForm loginPage;
    QWidget mainPage;

    QPushButton loginButton("Log In", &buttonsPage);
    QPushButton exitButton("Exit", &buttonsPage);


    QVBoxLayout mainLayout(&window);
    mainLayout.addWidget(&loginButton);
    mainLayout.addWidget(&exitButton);

    // Afișați fereastra principală
    window.show();

    return app.exec();
}
