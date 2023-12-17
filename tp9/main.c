#include <stdio.h>
#include <stdlib.h>

#include "../tp8/graphmath.h"

void floyd(GrapheMat* graph) {
  Matrice a, p;
  int n = graph->n;
  int nMax = graph->nMax;

  initFloyd(graph, &a, &p);

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i * nMax + k] != INFINI && a[k * nMax + j] != INFINI &&
            a[i * nMax + k] + a[k * nMax + j] < a[i * nMax + j]) {
          a[i * nMax + j] = a[i * nMax + k] + a[k * nMax + j];
          p[i * nMax + j] = p[k * nMax + j];
        }
      }
    }
    ecrireEtape(a, p, k, n, nMax);
  }
}

void initFloyd(GrapheMat* graph, Matrice* a, Matrice* p) {
  int nMax = graph->nMax;

  Matrice ta = (int*)malloc(sizeof(int) * nMax * nMax);
  Matrice tp = (int*)malloc(sizeof(int) * nMax * nMax);

  for (int i = 0; i < graph->n; i++) {
    for (int j = 0; j < graph->n; j++) {
      ta[i * nMax + j] = graph->valeur[i * nMax + j];
      tp[i * nMax + j] = i;
    }
  }
  *a = ta;
  *p = tp;
}

void ecrireEtape(Matrice a, Matrice p, int k, int ns, int nMax) {
  printf("passage par sommet %d\n", k);
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < ns; j++) {
      if (a[i * nMax + j] == INFINI) {
        printf(" %3s", "*");
      } else {
        printf(" %3d", a[i * nMax + j]);
      }
    }

    printf("%6s", " ");
    for (int j = 0; j < ns; j++) {
      printf(" %3d", p[i * nMax + j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  GrapheMat* graph = creerGrapheMat(100, true);

  // ajout des sommets
  for (int i = 0; i < 8; i++) {
    char vertexName[20];
    sprintf(vertexName, "S%d", i);

    ajouterUnSommet(graph, vertexName);
    //initialiser the valeur des arcs (i, i) => 0
    ajouterUnArc(graph, vertexName, vertexName, 0);
  }

  // ajout des arcs
  ajouterUnArc(graph, "S0", "S1", 25);
  ajouterUnArc(graph, "S0", "S6", 17);
  ajouterUnArc(graph, "S1", "S2", 30);
  ajouterUnArc(graph, "S1", "S3", 33);
  ajouterUnArc(graph, "S1", "S5", 15);
  ajouterUnArc(graph, "S2", "S3", 18);
  ajouterUnArc(graph, "S3", "S1", 33);
  ajouterUnArc(graph, "S4", "S3", 25);
  ajouterUnArc(graph, "S4", "S5", 26);
  ajouterUnArc(graph, "S4", "S7", 20);
  ajouterUnArc(graph, "S5", "S3", 35);
  ajouterUnArc(graph, "S5", "S1", 15);
  ajouterUnArc(graph, "S6", "S5", 22);

  ecrireGraphe(graph);
  printf("\n");

  // todo apply to the example given
  floyd(graph);
  return 0;
}