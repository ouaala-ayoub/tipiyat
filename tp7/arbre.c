#include "arbre.h"

#include <stdio.h>
#include <stdlib.h>

Node *findNode(Node *node, Object *toFind, int (*compare)(Object *, Object *)) {
  if (node == NULL) {
    return NULL;
  } else if (compare(node->reference, toFind) == 0) {
    return node;
  } else {
    Node *leftNode = findNode(node->left, toFind, compare);
    if (leftNode != NULL) {
      return leftNode;
    }
    return findNode(node->right, toFind, compare);
  }
}

Node *findNodeInTree(Tree *tree, Object *toFind,
                     int (*compare)(Object *, Object *)) {
  if (tree == NULL || tree->root == NULL) {
    return NULL;
  }
  return findNode(tree->root, toFind, compare);
}

int size(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return 1 + size(node->left) + size(node->right);
}

int treeSize(Tree *tree) {
  if (tree == NULL) {
    // printf("tree null\n");
    return 0;
  }
  return size(tree->root);
}

int max(int a, int b) { return a > b ? a : b; }

int height(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return 1 + max(height(node->left), height(node->right));
}
int treeHeight(Tree *tree) {
  if (tree == NULL || tree->root == NULL) {
    return 0;
  }
  return height(tree->root);
}
