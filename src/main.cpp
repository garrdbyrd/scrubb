#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Main program
    QApplication app(argc, argv);
    QMainWindow *window = MainWindow::build();
    window->show();
    return app.exec();
}
