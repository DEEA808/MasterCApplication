#include "TutorialGUI.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Repo.h"
#include "FileWatchList.h"
#include "CSV.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo r("Tut.txt.txt");
    FileWatchList* p = nullptr;
    p = new CSV("W.csv");
    Service serv(r, p, TutorialVal{});
    TutorialGUI w(serv);
    w.show();
    return a.exec();
}
