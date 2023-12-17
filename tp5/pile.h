#include "list.h"
#ifndef pile_h
#define pile_h

typedef List Pile;

Pile *createPile(char *(*afficher)(Object *), int (*comparer)(Object *, Object *));
int isEmpty(Pile* pile);
void push(Pile* pile, Object* obj);
Object* pop(Pile* pile);
void printPile(Pile* pile);
void freePile(Pile* pile);

#endif