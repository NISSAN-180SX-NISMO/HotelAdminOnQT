#include "QtWidgets/MainTabWindow//maintabwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainTabWindow m;
    m.show();
    return a.exec();
}