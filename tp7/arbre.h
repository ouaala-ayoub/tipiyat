#include "../tp6/arbre.h"

Node* findNode(Node* node, Object* toFind, int (*compare)(Object*, Object*));
Node* findNodeInTree(Tree* tree, Object* toFind, int (*compare)(Object*, Object*));

int size(Node* tree);
int treeSize(Tree *tree);

int height(Node* node);
int treeHeight(Tree* tree);