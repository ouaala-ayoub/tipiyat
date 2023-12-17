#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void initList(List *list, char *(*afficher)(Object *), int (*comparer)(Object *, Object *)){
    list->first = NULL;
    list->last = NULL;
    list->current = NULL;
    list->length = 0;
    list->afficher = afficher;
    list->comparer = comparer;
}

int isListEmpty(List* list){
    return list->length == 0;
}

int length(List* list){
    return list->length;
}

List* creerList(char *(*afficher)(Object *), int (*comparer)(Object *, Object *)){
    List *list = malloc(sizeof(List));
    initList(list, afficher, comparer);
    return list;
}

static Element* creerElement(){
    return (Element *) malloc(sizeof(Element));
}
void printLastAndFirst(List* list){
    printf("first is %s\n", list->afficher(list->first->reference));
    printf("last is %s\n", list->afficher(list->last->reference));
}
void insererEnTete(List* list, Object* object){
    Element *newElement = creerElement();
    newElement->reference = object;
    newElement->next = list->first;
    list->first = newElement;
    if(list->last == NULL){
        list->last = newElement;
    }
    list->length++;
}
void insererApres(List* list, Element* toInsertAfter, Object* object){
    if (toInsertAfter == NULL){
        insererEnTete(list, object);
    } else{
        Element *newElement = creerElement();
        newElement->reference = object;
        newElement->next = toInsertAfter->next;
        toInsertAfter->next = newElement;
        if (toInsertAfter == list->last){
            list->last = newElement;
        }
        list->length++;
    }
}

void insererALafin(List* list, Object* object){
    insererApres(list, list->last, object);
}
void resetList(List* list){
    list->current = list->first;
}

int isListEnd(List* list){
    return list->current == NULL;
}

Element* elementCourant(List* list){
    Element* courant = list-> current;
    if (list->current != NULL){
        list->current = list->current->next;
    }
    return courant;
}
Object *objectCourant(List *list){
    Element *courant = elementCourant(list);
    return courant == NULL ? NULL : courant->reference;
}

void printList(List* list){
    if (isListEmpty(list)){
        printf("List vide\n");
        return;
    }
    
    resetList(list);
    while(!isListEnd(list)){
        Object *obj = objectCourant(list);
        printf("%s\n", list->afficher(obj));
    }
}
Object* supprimerPremier(List* list){
    if(list ==NULL){
        printf("list non initialisee");
        return NULL;
    }
    Element* toDelete = list->first;
    if (!isListEmpty(list)) {
        list->first = toDelete->next;
        // free(toDelete);
        list->length--;

        if (list->first == NULL) {
            // The list is now empty
            list->last = NULL;
        }
    }
    return toDelete != NULL ? toDelete->reference : NULL;
}
Object* supprimerApres(List* list, Element* toDeleteAfter){
    if(toDeleteAfter ==NULL)
        return supprimerPremier(list);
    else{
        Element *toDelete = toDeleteAfter->next;
        if(toDelete != NULL){
            toDeleteAfter->next = toDelete->next;
            if (toDelete == list->last)
                list->last = toDeleteAfter;
            list->length--;
        }
        return toDelete != NULL ? toDelete->reference: NULL;
    }
}

Object* supprimerDernier(List* list) {
    if (isListEmpty(list)) {
        printf("La liste est vide\n");
        return NULL;
    }
    Object *deletedReference;

    if (list->first == list->last) {
        // Si la liste a un seul élément, supprimez-le et mettez à jour le premier et le dernier
        Element *toDelete = list->first;
        deletedReference = toDelete->reference;
        list->first = NULL;
        list->last = NULL;
        free(toDelete);
    } else {
        // Sinon, trouvez l'avant-dernier élément, supprimez le dernier et mettez à jour le dernier
        Element *current = list->first;
        while (current->next != list->last) {
            current = current->next;
        }

        Element *toDelete = list->last;
        deletedReference = toDelete->reference;

        current->next = NULL;
        list->last = current;

        free(toDelete);
    }

    list->length--;

    return deletedReference;
}


// Fonction pour supprimer un élément spécifique de la liste par référence
void supprimerElement(List *list, Object *objToDelete) {
    Element *current = list->first;
    Element *previous = NULL;

    while (current != NULL && list->comparer(current->reference, objToDelete) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // L'élément à supprimer n'a pas été trouvé dans la liste
        printf("L element n est pas dans la liste.\n");
        return ;
    }

    if (previous == NULL) {
        // L'élément à supprimer est le premier de la liste
        list->first = current->next;
    } else {
        // L'élément à supprimer n'est pas le premier
        previous->next = current->next;
    }

    // Si l'élément à supprimer est le dernier, mettez à jour le dernier
    if (current == list->last) {
        list->last = previous;
    }

    free(current);
    list->length--;

    printf("L element a ete supprime de la liste.\n");
}

Element *chercherElement(List *list, Object *objToSearch) {
    Element *current = list->first;

    while (current != NULL) {
        if (list->comparer(current->reference, objToSearch) == 0) {
            return current; // Element found
        }
        current = current->next;
    }

    printf("element not found");

    return NULL; // Element not found
}


void freeList(List* list){
    resetList(list);
    while (!isListEnd(list)){
        Element *current = elementCourant(list);
        free(current);
    }
    //i don't know about this 
    // initList(list, NULL, NULL);
}