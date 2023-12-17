#ifndef personne_h
#define personne_h
typedef char char15 [16];
typedef void Object;

typedef struct personne {
    char15 nom;
    char15 prenom;
} Personne;

Personne *creerPersonne(char* nom, char* prenom);
char *ecrirePersonne(Object* object);
int comparerPersonnes(Object *object1, Object *object2);
#endif