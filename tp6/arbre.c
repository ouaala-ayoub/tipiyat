#include "arbre.h"

#include <stdio.h>
#include <stdlib.h>

#include "string.h"

char *printString(Object *object) {
  if (object == NULL) {
    return "Object is NULL";
  }

  char *nom = (char *)object;

  return nom;
}

int compareStrings(Object *obj1, Object *obj2) {
  char *num1 = (char *)obj1;
  char *num2 = (char *)obj2;
  return strcmp(num1, num2);
}

Node *createNode(Object *object, Node *left, Node *right) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->reference = object;
  node->left = left;
  node->right = right;
  return node;
}

Node *createLeaf(Object *object) { return createNode(object, NULL, NULL); }

void initTree(Tree *tree, Node *rootToInit, char *(*toString)(Object *),
              int (*compare)(Object *, Object *)) {
  tree->root = rootToInit;
  tree->toString = toString;
  tree->compare = compare;
}
Tree *createTree(Node *root, char *(*toString)(Object *),
                 int (*compare)(Object *, Object *)) {
  Tree *newTree = malloc(sizeof(Tree));
  initTree(newTree, root, toString, compare);
  return newTree;
}

void printSpaces(int count) {
  // for (int i = 0; i < count; i++) {
  //   printf("    ");
  // }
}

void parcoursPrefixe(char *(*toString)(Object *), Node *node, int depth) {
  if (node != NULL) {
    // Print the current node
    printSpaces(depth * 4);
    printf("%s",
           toString(node->reference));  // Print the result of afficher directly

    // Recursively traverse the left and right subtrees
    parcoursPrefixe(toString, node->left, depth + 1);
    parcoursPrefixe(toString, node->right, depth + 1);
  }
}

void parcoursInfixe(char *(*toString)(Object *), Node *node, int depth) {
  if (node != NULL) {
    // Recursively traverse the left subtree
    parcoursInfixe(toString, node->left, depth + 1);

    // Print the current node
    printSpaces(depth * 4);
    printf("%s", toString(node->reference));

    // Recursively traverse the right subtree
    parcoursInfixe(toString, node->right, depth + 1);
  }
}

void parcoursPostfixe(char *(*toString)(Object *), Node *node, int depth) {
  if (node != NULL) {
    // Recursively traverse the left and right subtrees
    parcoursPostfixe(toString, node->left, depth + 1);
    parcoursPostfixe(toString, node->right, depth + 1);

    // Print the current node
    printSpaces(depth * 4);
    printf("%s", toString(node->reference));
  }
}