#ifndef GRID_H
#define GRID_H
#include<array>


class grid
{
public:
    grid();
    ~grid();
    void print_grid();
    void fill_case(int i, int a);
    void fill_grid(std::array<int,81>a);
    int index2line(int ind);
    int index2column(int ind);
    int index2square(int ind);
//    int isinsquare (int a, int p);
//    int isincolumn (int a, int p);
//    int isinline (int a, int p);
//    bool iscorrect(int p);
private :
    std::array<int,81> m_array;

};

#endif // GRID_H
