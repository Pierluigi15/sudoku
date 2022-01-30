#include "sudoku.h"
#include<iostream>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end



sudoku::sudoku(std::array<int,81> a,std::array<int,81> b)
{
    this->m_work_array=a;
    this->m_completed_array=b;
}

std::array<int,81> sudoku::check()
{
    std::array<int,81> res;
    res.fill(-1);
    for(int i=0;i<81;i++){
        if (m_work_array[i]!=0){
            if(m_work_array[i]!=m_completed_array[i]){
                res[i]=1;}
        }
    }
    return res;
}

std::array<int,81> sudoku::getwg()
{
    return m_work_array;
}

std::array<int,81> sudoku::getcg()
{
    return m_completed_array;
}

void sudoku::updatewg(int i,std::string s)
{
    std::array<std::string,9> nombres={"1","2","3","4","5","6","7","8","9"};
    bool exists = std::find(std::begin(nombres), std::end(nombres), s) != std::end(nombres);
    if(exists){
        int a =std::stoi(s);
        m_work_array[i]=a;
    }else{m_work_array[i]=0;std::cout<<"Veuillez rentrer un chiffre entre 1 et 9"<<std::endl;}

}
