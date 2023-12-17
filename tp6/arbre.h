#ifndef TREE_H
#define TREE_H

typedef void Object;

typedef struct node {
  Object *reference;
  struct node *left;
  struct node *right;
} Node;

typedef struct {
  Node *root;
  char *(*toString)(Object *);
  int (*compare)(Object *, Object *);
} Tree;
char *printString(Object *object);
int compareStrings(Object *obj1, Object *obj2);
Node *createNode(Object *object, Node *left, Node *right);
Node *createLeaf(Object *object);
void initTree(Tree *tree, Node *root, char *(*toString)(Object *),
              int (*compare)(Object *, Object *));
Tree *createTree(Node *root, char *(*toString)(Object *),
                 int (*compare)(Object *, Object *));
void parcoursPrefixe(char *(*toString)(Object *), Node *root, int depth);
void parcoursInfixe(char *(*toString)(Object *), Node *node, int depth);
void parcoursPostfixe(char *(*toString)(Object *), Node *node, int depth);

#endif