#include "personne.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Personne *creerPersonne(char* nom, char* prenom){
    Personne *nouveauPersonne = malloc(sizeof(Personne));
    strcpy(nouveauPersonne->nom, nom);
    strcpy(nouveauPersonne->prenom, prenom);
    return nouveauPersonne;
}

char *ecrirePersonne(Object* object){
    if (object == NULL)
    {
        return "Object is NULL";
    }
    
    Personne *p = (Personne*)object;
    char *output = (char*) malloc(sizeof(Personne));

    snprintf(output, sizeof(Personne), "%s %s", p->nom, p->prenom);
    return output;
}

int comparerPersonnes(Object *object1, Object *object2){
    Personne *p1 = (Personne *)object1;
    Personne *p2 = (Personne *)object2;
    return strcmp(p1->nom, p2->nom);
}