#include "sudoku.h"
#include<iostream>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end



sudoku::sudoku(std::array<int,81> a,std::array<int,81> b)
{
    //cette méthode initialise le sudoku, un sudoku regroupe 2 arrays étant ses attributs, 1 représentant la grille incomplète étant modifiée
    //et l'autre la grille solution, par défaut un sudoku vide est créé à partir de 2 arrays remplis de zéros
    this->m_work_array=a;
    this->m_completed_array=b;
}

std::array<int,81> sudoku::check()
{
    //cette méthode renvoie un array de -1 et de 1, par comparaison entre la grille en train d'être complétée
    //et la grille solution, si pour un certain indice on a un -1 cela signifie que l'entrée était correcte ou que rien n'a été entré encore
    //si on a un 1, cela signifie que ce n'est pas le bon chiffre
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
    //méthode permettant d'accéder à l'attribut m_work_array représentant la grille en train d'être modifiée
    return m_work_array;
}

std::array<int,81> sudoku::getcg()
{
    //méthode permettant d'accéder à l'attribut m_completed_array représentant la grille solution
    return m_completed_array;
}

void sudoku::updatewg(int i,std::string s)
{
    //méthode permettant d'actualiser l'attribut m_work_array, lorsqu'une string est rentrée dans une case d'indice i
    std::array<std::string,9> nombres={"1","2","3","4","5","6","7","8","9"};
    //il faut vérifier que l'entrée est bien un entier entre 1 et 9
    bool exists = std::find(std::begin(nombres), std::end(nombres), s) != std::end(nombres);
    if(exists){
        int a =std::stoi(s);
        m_work_array[i]=a;
    }else{m_work_array[i]=0;std::cout<<"Veuillez rentrer un chiffre entre 1 et 9"<<std::endl;}

}

bool sudoku::isPossible(int num, int ind)
{
    //cette fonction vérifie si le placement de num dans la case correspondant à l'indice ind
    //est compatible avec les autres chiffres présent dans la case ligne et colonne.

    if (not isInLine(num,ind)&& not isInColumn(num,ind)&& not isInBox(num,ind)){
        return true;
    }

    return false;
}

bool sudoku::isInLine(int num, int ind)
{
    //vérifie si num est déjà présent dans la ligne qui correspond à la case d'indice ind
    int line= ind/9;
    for (int j=line*9;j<(line+1)*9;j++)
        //cette boucle parcourt toute la ligne sur l'ensemble des indices j des colonnes de la grille
        if(num==m_work_array[j]){return true;}
    return false;
}

bool sudoku::isInColumn(int num, int ind)
{
    //vérifie si num est déjà présent dans la colonne qui correspond à la case d'indice ind
    int col= ind%9;
    for (int i=col;i<80+col;i=i+9)
        //cette boucle parcourt toute la colonne sur l'ensemble des indices j des lignes de la grille
        if(num==m_work_array[i]){return true;}
    return false;
}
bool sudoku::isInBox(int num, int ind)
{
    //vérifie si num est déjà présent dans la boite qui correspond à la case d'indice ind
    int col= ind%9;
    int line= ind/9;
    int big_line=line/3;//donne la ligne de la boite, de 0 à 2
    int big_col=col/3;//donne la colonne de la boit, de 0 à 2
    //int box =big_line*3+big_col;
    int first_index=27*big_line+3*big_col;
    for (int i=first_index;i<=first_index+2;i++)
    {//cette boucle parcourt toutes les cases composant la première ligne de la boite
        if(num==m_work_array[i]){return true;}}
    first_index+=9;
    for (int i=first_index;i<=first_index+2;i++)
    {//cette boucle parcourt toutes les cases composant la deuxième ligne de la boite
        if(num==m_work_array[i]){return true;}}
    first_index+=9;
    for (int i=first_index;i<=first_index+2;i++)
    {//cette boucle parcourt toutes les cases composant la troisième ligne de la boite
        if(num==m_work_array[i]){return true;}}
    return false;
}

void sudoku::solve()
{
    //résout le sudoku grace à le récursivité et au bactracking

}
