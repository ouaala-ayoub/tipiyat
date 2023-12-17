#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../tp6/arbre.h"
#include "arbre.h"

int menu() {
  printf("\n\n GESTION D'ARBRES \n\n");
  printf("\n\n ARBRES BINAIRES \n\n");
  printf(" 0 - Fin du programme\n");
  printf("\n");
  printf(" 1 - Création de l'arbre généalogique\n");
  printf(" 2 - Création de l'arbre de l'expression arithmétique\n");
  printf("\n");
  printf(" 3 - Parcours préfixé\n");
  printf(" 4 - Parcours infixé\n");
  printf(" 5 - Parcours postfixé\n");
  printf(" 6 - Trouver Noeud \n");
  printf(" 7 - Taille \n");
  printf(" 8 - Hauteur \n");
  printf(" 9 - Parcours en Largeur \n");
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
                 Tree **trees) {
  int input = getInput();
  handleParcours(trees[input], parcous);
}

void showInfo(int (*info)(Tree *), Tree **trees) {
  int input2 = getInput();
  Tree *tree = trees[input2];
  if (tree == NULL) {
    printf("l arbre est null\n");
  } else {
    printf("La taile de l arbre est %d\n", info(tree));
  }
}

int main() {
  Tree *geneologyTree = NULL;
  Tree *arithmeticTree = NULL;
  Tree *trees[2] = {geneologyTree, arithmeticTree};

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
          trees[0] = geneologyTree;
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
          trees[1] = arithmeticTree;
          printf("cree avec success");
        } else {
          printf("Deja cree");
        }

        break;

      case 3:
        handleCases(parcoursPrefixe, trees);
        break;

      case 4:
        handleCases(parcoursInfixe, trees);
        break;

      case 5:
        handleCases(parcoursPostfixe, trees);
        break;

      case 6:
        int input = getInput();
        char query[20];

        printf("Que cherchez vous ? ");

        scanf("%s", query);

        Node *resNode = findNodeInTree(trees[input], query, compareStrings);
        if (resNode == NULL) {
          printf("Node non trouvee");
        } else {
          printf("Node trouvee de valeur %s", printString(resNode->reference));
        }

        break;

      case 7:
        showInfo(treeSize, trees);
        break;

      case 8:
        showInfo(treeHeight, trees);
        break;

      case 9:
        printf("Not yet implemented");
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
