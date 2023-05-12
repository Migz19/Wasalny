#include <QtWidgets/QApplication>
#include<qlabel>
#include<qlineedit>
#include"mainwindow.h"
#include"File.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    File file;
    file.load();

    w.show();

    return app.exec();
}