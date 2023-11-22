#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

    // add other things

    mainWindow.show();
    return app.exec();
}
