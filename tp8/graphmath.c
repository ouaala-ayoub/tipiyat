#include "graphmath.h"

#include <stdlib.h>
#include <string.h>

GrapheMat* creerGrapheMat(int nMax, int value) {
  GrapheMat* newGraph = (GrapheMat*)malloc(sizeof(GrapheMat));
  newGraph->n = 0;
  newGraph->nMax = nMax;
  newGraph->value = value;
  newGraph->nomS = (NomSom*)malloc(sizeof(NomSom) * nMax);
  newGraph->element = (Matrice)malloc(sizeof(int) * nMax * nMax);
  newGraph->valeur = (Matrice)malloc(sizeof(int) * nMax * nMax);
  newGraph->marque = (booleen*)malloc(sizeof(booleen) * nMax);

  // valeurs par defaut
  for (int i = 0; i < nMax; i++) {
    for (int j = 0; j < nMax; j++) {
      newGraph->element[i * nMax + j] = false;
      newGraph->valeur[i * nMax + j] = INFINI;
    }
  }

  resetMarqued(newGraph);
  return newGraph;
}

void resetMarqued(GrapheMat* graph) {
  for (int i = 0; i < graph->n; i++) {
    graph->marque[i] = false;
  }
}

void detruireGraphe(GrapheMat* graph) {
  free(graph->nomS);
  free(graph->element);
  free(graph->valeur);
  free(graph->marque);
  free(graph);
}

static int rang(GrapheMat* graph, NomSom nom) {
  int i = 0;
  booleen trouve = false;
  while (i < graph->n && !trouve) {
    // printf("nomS %s and nom %s", graph->nomS[i], nom);
    trouve = strcmp(graph->nomS[i], nom) == 0;
    if (!trouve) i++;
  }
  return trouve ? i : -1;
}

void ajouterUnSommet(GrapheMat* graph, NomSom nom) {
  int index = rang(graph, nom);
  if (index == -1) {
    if (graph->n < graph->nMax) {
      strcpy(graph->nomS[graph->n], nom);
      graph->n++;
    } else {
      printf("Nombre max des sommets est %d\n", graph->nMax);
    }
  } else {
    printf("Element existe deja\n");
  }
}

void ajouterUnArc(GrapheMat* graph, NomSom somD, NomSom somA, int cout) {
  int indexD = rang(graph, somD);
  int indexA = rang(graph, somA);
  if (indexA != -1 && indexA != -1) {
    graph->valeur[indexD * graph->nMax + indexA] = cout;
    graph->element[indexD * graph->nMax + indexA] = true;
  }
}
void ecrireGraphe(GrapheMat* graph) {
  for (int i = 0; i < graph->n; i++) {
    printf("%s ", graph->nomS[i]);
  }
  printf("\n");
  for (int i = 0; i < graph->n; i++) {
    printf("%s : ", graph->nomS[i]);
    for (int j = 0; j < graph->n; j++) {
      int current = i * graph->nMax + j;
      if (graph->element[current]) {
        printf("%s (%d) ", graph->nomS[j], graph->valeur[current]);
      }
    }
    printf(";\n");
  }
}
void parcoursProfond(GrapheMat* graph) {
  resetMarqued(graph);
  for (int i = 0; i < graph->n; i++) {
    if (!graph->marque[i]) profondeur(graph, i);
  }
}
static void profondeur(GrapheMat* graph, int numeroDuSommet) {
  int nMax = graph->nMax;
  graph->marque[numeroDuSommet] = true;

  printf("%s\n", graph->nomS[numeroDuSommet]);

  for (int i = 0; i < graph->n; i++) {
    booleen elementExist = graph->element[numeroDuSommet * nMax + i] == true;
    booleen isMarqued = graph->marque[i];

    if (elementExist && !isMarqued) {
      profondeur(graph, i);
    }
  }
}