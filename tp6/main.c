#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {
  printf("\n\n GESTION D ARBRES \n\n");
  printf("\n\n ARBRES BINAIRES \n\n");
  printf(" 0 - Fin du programme\n");
  printf("\n");
  printf(" 1 - Creation de l arbre genealogique\n");
  printf(" 2 - Creation de l arbre de l expression arithmetique\n");
  printf("\n");
  printf(" 3 - Parcours prefixe\n");
  printf(" 4 - Parcours infixe\n");
  printf(" 5 - Parcours postfixe\n");
  printf("\n");
  printf("Votre choix ? ");
  int cod;
  scanf("%d", &cod);
  getchar();
  printf("\n");
  return cod;
}

int getInput() {
  printf("0: arbre geneologique\n");
  printf("1: arbre arithmetique\n");
  printf("Choix ?");
  int input;
  scanf("%d", &input);
  while (input != 0 && input != 1) {
    printf("choice invalide ");
    scanf("%d", &input);
  }
  return input;
}

void handleParcours(Tree *tree,
                    void (*parcous)(char *(*toString)(Object *), Node *, int)) {
  if (tree != NULL) {
    parcous(printString, tree->root, 0);
  } else {
    printf("Arbre non initialise");
  }
}
void handleCases(void (*parcous)(char *(*toString)(Object *), Node *, int),
                 Tree *tree1, Tree *tree2) {
  int input = getInput();
  switch (input) {
  case 0:
    handleParcours(tree1, parcous);
    break;

  default:
    handleParcours(tree2, parcous);
    break;
  }
}

int main() {

  Tree *geneologyTree = NULL;
  Tree *arithmeticTree = NULL;

  int choice = menu();

  while (choice != 0) {
    switch (choice) {
    case 1:
      if (geneologyTree == NULL) {
        Node *root = createNode(
            "Samir",
            createNode(
                "Kamal",
                createNode("Yassin", NULL,
                           createNode("Hind", NULL, createLeaf("Yassmine"))),
                createNode("Sarah", createLeaf("Karim"), NULL)),
            NULL);
        geneologyTree = createTree(root, printString, compareStrings);
        printf("cree avec success");
      } else {
        printf("Deja cree");
      }
      break;

    case 2:
      if (arithmeticTree == NULL) {
        // for test only
        // Node *test = createNode("1", createLeaf("2"), createLeaf("3"));

        Node *root = createNode(
            "-",
            createNode("*", createNode("+", createLeaf("a"), createLeaf("b")),
                       createNode("-", createLeaf("c"), createLeaf("d"))),
            createLeaf("e"));
        arithmeticTree = createTree(root, printString, compareStrings);
        printf("cree avec success");
      } else {
        printf("Deja cree");
      }

      break;

    case 3:
      handleCases(parcoursPrefixe, geneologyTree, arithmeticTree);
      break;
    case 4:
      handleCases(parcoursInfixe, geneologyTree, arithmeticTree);
      break;
    case 5:
      handleCases(parcoursPostfixe, geneologyTree, arithmeticTree);
      break;
    default:
      printf("choix invalide");
      break;
    }
    choice = menu();
  }

  getchar();
  return 0;
}
