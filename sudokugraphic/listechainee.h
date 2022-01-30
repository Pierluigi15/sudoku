#include <iostream>
using namespace std;
#include <noeud.h>

#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H



// classe listechainee pour implémenter une liste chainée
class listechainee {


public:
    noeud* head;
    // constructeur par défaut
    listechainee() { head = NULL; }

    // fonction pour insérer un noeud à la fin d'une liste chainée
    void insertnoeud(int);

    // méthode pour afficher la liste

    void printList();
};

#endif // LISTECHAINEE_H
