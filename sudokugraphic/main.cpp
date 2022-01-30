#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<array>
#include "grid.h"
#include "sudoku.h"

using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w ;
    w.show();

    return a.exec();
}
