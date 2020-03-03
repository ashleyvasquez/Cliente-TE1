#include <iostream>
#include <QApplication>
#include "Window.h"

using namespace std;
Window * window;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    window = new Window();
    window->show();

    return a.exec();

}
