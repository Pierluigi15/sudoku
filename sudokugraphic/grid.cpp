#include "grid.h"
#include <array>
#include <iostream>

using namespace std;


grid::grid()
{
    m_array.fill(0);
}

grid::~grid()
{

}

void grid::print_grid(){
    for ( int i=0; i<81; i++){
       if (i%9==0){
           cout << '\n';}
       cout << m_array.at(i) << " ";
    }
    cout << '\n';
}

void grid::fill_case(int i,int a){
    m_array[i]=a;
}

void grid::fill_grid(array<int,81>a)
{
    for ( int i=0; i<81; i++)
    {
        m_array[i]=a[i];
    }
}

int grid::index2line(int ind)
{
    return ind/9;
}

int grid::index2column(int ind)
{
    return ind%9;
}

int grid::index2square(int ind)
{
    int line = grid::index2line(ind);
    int column =  grid::index2column(ind);
    int divline = line/3;
    int divcol = column/3;
    return divline*3+divcol;
}
//int grid::isinsquare (int a, int p)
//{
//    int square = grid::index2square(p);
//    for

//}
//int isincolumn (int a);
//int isinline (int a);
//bool iscorrect(int p);

