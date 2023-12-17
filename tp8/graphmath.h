/* graphemat.h */
#ifndef GRAPH_MATH_h
#define GRAPH_MATH_h

#include <stdio.h>
typedef int booleen;
#define false 0
#define true 1
typedef char NomSom[20];  // nom d'un sommet
#define INFINI INT_MAX
typedef int* Matrice;
typedef struct {
  int n;            // nombre de sommets
  int nMax;         // nombre max de sommets
  booleen value;    // graphe valué ou non
  NomSom* nomS;     // noms des sommets
  Matrice element;  // existence d'un arc (i, j)
  Matrice valeur;   // cout de l'arc (i, j)
  booleen* marque;  // sommet marqué (visité) ou non
} GrapheMat;

GrapheMat* creerGrapheMat(int nMax, int value);
void resetMarqued(GrapheMat* graph);
void detruireGraphe(GrapheMat* graph);
void ajouterUnSommet(GrapheMat* graph, NomSom nom);
void ajouterUnArc(GrapheMat* graph, NomSom somD, NomSom somA, int cout);
void ecrireGraphe(GrapheMat* graph);
void parcoursProfond(GrapheMat* graph);
static void profondeur(GrapheMat* graph, int numeroDuSommet);

#endif