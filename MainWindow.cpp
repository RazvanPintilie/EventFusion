#include "MainWindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) 
{
    setWindowTitle("Event Fusion");
    this->resize(900, 600);

    QPushButton* exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(700, 500, 100, 30);

    connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}
