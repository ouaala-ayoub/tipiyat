#include <stdlib.h>
#include "pile.h"
#include "list.h"

Pile *createPile(char *(*afficher)(Object *), int (*comparer)(Object *, Object *)){
    return creerList(afficher, comparer);
}
int isEmpty(Pile* pile){
    return isListEmpty(pile);
}
void push(Pile* pile, Object* obj){
    insererEnTete(pile, obj);
}
Object* pop(Pile* pile){
    if (isEmpty(pile)){
        return NULL;
    } else{
        return supprimerPremier(pile);
    }
}
void printPile(Pile* pile){
    printList(pile);
}
void freePile(Pile* pile){
    freeList(pile);
}