#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget exitPage;
    exitPage.setWindowTitle("Exit Page");

    QPushButton exitButton("Exit", &exitPage);
    exitButton.setGeometry(100, 50, 100, 30);

    QObject::connect(&exitButton, &QPushButton::clicked, &app, &QApplication::quit);

    exitPage.show();

    return app.exec();
}
