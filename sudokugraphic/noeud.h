#include <iostream>
using namespace std;
#ifndef NOEUD_H
#define NOEUD_H

// Classe noeud pour représenter le noeud d'une liste chaînée
class noeud
{
public:
    int data;
    noeud* next;

    // Constructeur par défaut
    noeud()
    {
        data = 0;
        next = NULL;
    }

    // Constructeur paramétré
    noeud(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


#endif // NOEUD_H
