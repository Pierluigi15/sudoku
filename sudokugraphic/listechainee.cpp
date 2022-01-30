#include "listechainee.h"

// Méthode pour insérer un nouveau noeud
void listechainee::insertnoeud(int data)
{
    // créer le nouveau noeud
    noeud* newnoeud = new noeud(data);

    // assigne la nouvelle head
    if (head == NULL) {
        head = newnoeud;
        return;
    }

    // parcourt la liste jusqu'à la fin
    noeud* curr = head;
    while (curr->next != NULL) {

        // Mise à jour du noeud courant
        curr = curr->next;
    }

    // l'insère à la fin de la liste.
    curr->next = newnoeud;
}

// fonction pour l'affichage de la liste
void listechainee::printList()
{
    noeud* curr = head;

    // vérifie si la list est vide
    if (head == NULL) {
        cout << "Liste vide" << endl;
        return;
    }

    // parcourt la liste
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
