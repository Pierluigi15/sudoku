#ifndef SUDOKU_H
#define SUDOKU_H
#include<array>
#include "listechainee.h"
#include "noeud.h"


class sudoku
{
public:
    sudoku(std::array<int,81> a = std::array<int,81> {0} ,std::array<int,81> b=std::array<int,81> {0});
    std::array<int,81> check();
    std::array<int,81> getwg();
    std::array<int,81> getcg();
    void updatewg(int i, std::string s);
    void updatewa(int i,int k);
    bool isPossible(int num, int ind);
    bool isInLine(int num, int ind);
    bool isInColumn(int num, int ind);
    bool isInBox(int num, int ind);
    bool solve();
    void find_possible_numbers();
    void number_of_candidates();
    void listedeparcours();
    std::array<int,81> solution();
    std::array<int,81> m_possible_numbers;
    std::array<std::array<int,2>,81> m_number_of_candidates;
    listechainee m_listedeparcours;


private:
   std::array<int,81> m_work_array;
   std::array<int,81> m_test_array;
   std::array<int,81> m_completed_array;


};

#endif // SUDOKU_H
