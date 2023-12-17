// list.c
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize an empty list
void initList(IntegerList* list) {
    list->first = NULL;
    list->last = NULL;
    list->current = NULL;
    list->length = 0;
}

// Insert a new element with the given data at the start of the list
void insertStart(IntegerList* list, int data) {
    if(list ==NULL){
        printf("list non initialisee");
        return;
    }
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (newElement == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newElement->data = data;
    newElement->next = list->first;

    list->first = newElement;

    if (list->last == NULL) {
        // This is the first element in the list
        list->last = newElement;
    }

    list->length++;
}

// Insert a new element with the given data at the end of the list
void insertEnd(IntegerList* list, int data) {
    if(list ==NULL){
        printf("list non initialisee");
        return;
    }
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (newElement == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newElement->data = data;
    newElement->next = NULL;

    if (list->last == NULL) {
        // This is the first element in the list
        list->first = newElement;
        list->last = newElement;
    } else {
        list->last->next = newElement;
        list->last = newElement;
    }

    list->length++;
}

// Delete the element at the start of the list
void deleteStart(IntegerList* list) {
    if(list ==NULL){
        printf("list non initialisee");
        return;
    }
    if (list->first != NULL) {
        Element* toDelete = list->first;
        list->first = toDelete->next;
        free(toDelete);
        list->length--;

        if (list->first == NULL) {
            // The list is now empty
            list->last = NULL;
        }
    }
}

// Delete the element at the end of the list
void deleteEnd(IntegerList* list) {
    if(list ==NULL){
        printf("list non initialisee");
        return;
    }
    if (list->first != NULL) {
        Element* toDelete = list->first;
        Element* previous = NULL;

        while (toDelete->next != NULL) {
            previous = toDelete;
            toDelete = toDelete->next;
        }

        if (previous != NULL) {
            previous->next = NULL;
            list->last = previous;
        } else {
            // The list has only one element
            list->first = NULL;
            list->last = NULL;
        }

        free(toDelete);
        list->length--;

        if (list->first == NULL) {
            // The list is now empty
            list->last = NULL;
        }
    }
}

// Delete a specific element from the list
void deleteElement(IntegerList* list, int data) {
    if(list ==NULL){
        printf("list non initialisee");
        return;
    }
    Element* current = list->first;
    Element* previous = NULL;
    int found = -1; 

    while (current != NULL) {
        if (current->data == data) {
            found = 0;
            // If the element to delete is the first element
            if (previous == NULL) {
                list->first = current->next;
            } else {
                previous->next = current->next;
            }

            // If the element to delete is the last element
            if (current->next == NULL) {
                list->last = previous;
            }

            // Free the memory of the element to delete
            free(current);

            // Decrement the length of the list
            list->length--;

            return;
        }

        // Move to the next element
        previous = current;
        current = current->next;
    }
    if (!found){
        printf("element non existant dans la liste");
    } else {
        printf("element supprimee avec success");
    }
    
}

// Print the elements of the list
void printList(IntegerList* list) {
    if (list == NULL){
        printf("List non initialise");
        return;
    }
    if (list->length == 0){
        printf("List vide");
        return;
    }
    
    Element* current = list->first;

    while (current != NULL) {
        printf("%d", current->data);
        if (current != list->last){
            printf("->");
        }
        current = current->next;
    }

    printf("\n");
}

// Find a specific element in the list
void findElement(IntegerList* list, int toFind) {
    if(list ==NULL){
        printf("list non initialisee");
        return;
    }
    Element* current = list->first;

    while (current != NULL) {
        if (current->data == toFind) {
            printf("Element found with value: %d\n", toFind);
            return;  // Element found, exit the function
        }
        current = current->next;
    }

    // Element not found
    printf("Element with value %d not found in the list.\n", toFind);
}

// Free the memory allocated for the list
void freeList(IntegerList* list) {
    if(list ==NULL){
        printf("list non initialisee");
        return;
    }
    Element* current = list->first;
    Element* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->first = NULL;
    list->last = NULL;
    list->current = NULL;
    list->length = 0;
}
