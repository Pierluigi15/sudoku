#ifndef SUDOKU_H
#define SUDOKU_H
#include<array>


class sudoku
{
public:
    sudoku(std::array<int,81> a = std::array<int,81> {0} ,std::array<int,81> b=std::array<int,81> {0});
    std::array<int,81> check();
    std::array<int,81> getwg();
    std::array<int,81> getcg();
    void updatewg(int i, std::string s);

private:
   std::array<int,81> m_work_array;
   std::array<int,81> m_completed_array;
};

#endif // SUDOKU_H
