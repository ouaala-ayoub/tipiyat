#include "personne.h"
#ifndef list_h
#define list_h
typedef struct element {
    Object* reference;
    struct element* next;
} Element;

typedef struct list{
    Element *first;
    Element *last;
    Element *current;
    int length;
    char* (*afficher) (Object*);
    int (*comparer) (Object*, Object*);
} List;

void initList(List *list, char *(*afficher)(Object *), int (*comparer)(Object *, Object *));
List *creerList(char *(*afficher)(Object *), int (*comparer)(Object *, Object *));
int isEmpty(List *list);
int length(List *list);
static Element* creerElement();
void insererEnTete(List *list, Object *object);
void insererApres(List *list, Element* toInsertAfter, Object *object);
void insererALafin(List *list, Object *object);
void resetList(List *list);
int isListEnd(List *list);
Element* elementCourant(List *list);
Object *objectCourant(List *list);
void printList(List *list);
Object* supprimerPremier(List *list);
Object* supprimerApres(List *list, Element *toDeleteAfter);
Object* supprimerDernier(List *list);
void supprimerElement(List *list, Object *objToDelete);
Element* chercherElement(List *list, Object *objToSearch);
void freeList(List *list);

//todo! delete
void printLastAndFirst(List *list);

#endif