#include "personne.h"
#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

Personne *getUserInput() {
  char nom[16], prenom[16];
  printf("Entrez le nom ");
  scanf("%s", nom);
  printf("Entrez le prenom ");
  scanf("%s", prenom);
  return creerPersonne(nom, prenom);
}

int menu() {
  printf("\n");
  printf("0 - initialiser la pile\n");
  printf("1 - empiler\n");
  printf("2 - depiler\n");
  printf("3 - afficher la pile\n");
  printf("4 - detruire la pile\n");
  printf("5 - Fin\n");
  printf("\n");
  printf("Votre choix ? ");
  int cod;
  scanf("%d", &cod);
  printf("\n");
  return cod;
}

int main() {
  Pile *pile = createPile(ecrirePersonne, comparerPersonnes);
  int choice = menu();
  while (choice != 5) {
    switch (choice) {
    case 0: {
      pile = createPile(ecrirePersonne, comparerPersonnes);
      break;
    }
    case 1: {
      Personne *input = getUserInput();
      push(pile, input);
      break;
    }
    case 2: {
      Object *res = pop(pile);
      if (res != NULL) {
        printf("element supprimee avec success\n");
      }
      break;
    }
    case 3: {
      printPile(pile);
      break;
    }
    case 4: {
      freePile(pile);
      break;
    }
    default:
      printf("choix invalide");
      break;
    }
    choice = menu();
  }
  getchar();
  return 0;
}
