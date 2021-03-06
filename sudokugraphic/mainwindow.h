#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>
#include <QLineEdit>
#include "sudoku.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent=nullptr);
    ~MainWindow();
    void FillMainWindow(std::array<int,81>a);
    void ColorMainWindow();
    void checkgrid();
    void setSudoku(sudoku s);
    void deleteAll();

private:
    Ui::MainWindow *ui;
    std::array<QLineEdit*,81> listcase ;
    sudoku worksudoku;
    sudoku sudoku_facile{{0,5,0,0,8,0,0,0,3,0,0,4,7,0,0,2,0,0,6,0,0,0,0,2,0,1,0,7,4,0,0,3,0,1,0,0,5,0,0,1,0,6,0,0,4,0,0,1,0,2,0,0,6,5,0,3,0,5,0,0,0,0,1,0,0,2,0,0,4,7,0,0,1,0,0,0,6,0,0,3,0},{2,5,7,6,8,1,9,4,3,9,1,4,7,5,3,2,8,6,6,8,3,9,4,2,5,1,7,7,4,6,8,3,5,1,9,2,5,2,8,1,9,6,3,7,4,3,9,1,4,2,7,8,6,5,4,3,9,5,7,8,6,2,1,8,6,2,3,1,4,7,5,9,1,7,5,2,6,9,4,3,8}};
    sudoku sudoku_moyen{{3,9,0,0,0,0,0,0,7,0,0,1,0,0,0,0,4,0,6,0,0,5,0,0,8,0,0,0,0,0,0,0,0,0,8,0,0,1,0,0,0,0,2,0,5,0,0,7,0,9,0,6,0,0,0,0,4,0,0,5,0,7,3,0,0,0,6,0,0,0,0,0,9,0,0,8,3,0,0,0,0},{3,9,8,4,1,6,5,2,7,7,5,1,2,8,9,3,4,6,6,4,2,5,7,3,8,9,1,2,3,6,1,5,4,7,8,9,4,1,9,7,6,8,2,3,5,5,8,7,3,9,2,6,1,4,8,6,4,9,2,5,1,7,3,1,2,3,6,4,7,9,5,8,9,7,5,8,3,1,4,6,2}};
    sudoku sudoku_difficile{{0,0,1,0,0,3,0,0,0,0,6,0,0,0,0,8,0,0,0,3,0,0,0,4,5,1,0,0,9,0,2,0,0,7,0,4,0,0,0,0,6,0,0,0,0,1,0,2,0,0,8,0,3,0,0,1,5,7,0,0,0,8,0,0,0,9,0,0,0,0,4,0,0,0,0,1,0,0,2,0,0},{5,2,1,8,9,3,4,6,7,4,6,7,5,1,2,8,9,3,9,3,8,6,7,4,5,1,2,8,9,6,2,3,1,7,5,4,3,5,4,9,6,7,1,2,8,1,7,2,4,5,8,9,3,6,2,1,5,7,4,6,3,8,9,7,8,9,3,2,5,6,4,1,6,4,3,1,8,9,2,7,5}};
};
#endif // MAINWINDOW_H
