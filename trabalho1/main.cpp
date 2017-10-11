#include "mainwindow.h"
#include <QApplication>
#include "posfixa.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   // posfixa pos;
   //string teste = pos.converte("a+b(aa");
   //cout << teste << std::endl;


    return a.exec();
}
