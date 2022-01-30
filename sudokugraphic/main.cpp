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
    sudoku sudoku_test{{0,5,0,0,8,0,0,0,3,0,0,4,7,0,0,2,0,0,6,0,0,0,0,2,0,1,0,7,4,0,0,3,0,1,0,0,5,0,0,1,0,6,0,0,4,0,0,1,0,2,0,0,6,5,0,3,0,5,0,0,0,0,1,0,0,2,0,0,4,7,0,0,1,0,0,0,6,0,0,3,0},{2,5,7,6,8,1,9,4,3,9,1,4,7,5,3,2,8,6,6,8,3,9,4,2,5,1,7,7,4,6,8,3,5,1,9,2,5,2,8,1,9,6,3,7,4,3,9,1,4,2,7,8,6,5,4,3,9,5,7,8,6,2,1,8,6,2,3,1,4,7,5,9,1,7,5,2,6,9,4,3,8}};
    //tests fonction isInLine
//    cout<<sudoku_test.isInLine(8,3)<<endl;
//    cout<<sudoku_test.isInLine(9,8)<<endl;
//    cout<<sudoku_test.isInLine(1,64)<<endl;
    //tests fonction isInColumn
//    cout<<sudoku_test.isInColumn(4,6)<<endl;
//    cout<<sudoku_test.isInColumn(2,6)<<endl;
//    cout<<sudoku_test.isInColumn(5,1)<<endl;
    //tests fonction isInBox
//    cout<<sudoku_test.isInBox(4,34)<<endl;
//    cout<<sudoku_test.isInBox(4,40)<<endl;
    //tests fonction isPossible
//    cout<<sudoku_test.isPossible(2,2)<<endl;
//    cout<<sudoku_test.isPossible(2,3)<<endl;
//    cout<<sudoku_test.isPossible(2,0)<<endl;
    sudoku_test.find_possible_numbers();
//    cout<<"1"<<(0b000000100 & 0b00000100)<<endl;
//    cout<<"0"<<(0b000000100 & 1<<2)<<endl;
    cout<<sudoku_test.m_possible_numbers[0]<<endl;
//    cout<<sudoku_test.m_possible_numbers[0]<<endl;


    QApplication a(argc, argv);
    MainWindow w ;
    w.show();

    return a.exec();
    return 1;
}
