#include <stdio.h>
#include <stdlib.h>

#include "graphmath.h"

int main() {
  GrapheMat* graph = creerGrapheMat(4, true);

  // ajout des sommets
  ajouterUnSommet(graph, "S0");
  ajouterUnSommet(graph, "S1");
  ajouterUnSommet(graph, "S2");
  ajouterUnSommet(graph, "S3");

  // ajout des arcs
  ajouterUnArc(graph, "S0", "S1", 1);
  ajouterUnArc(graph, "S0", "S2", 2);
  ajouterUnArc(graph, "S1", "S0", 3);
  ajouterUnArc(graph, "S1", "S3", 4);
  ajouterUnArc(graph, "S2", "S1", 5);
  ajouterUnArc(graph, "S2", "S3", 6);
  ajouterUnArc(graph, "S3", "S1", 7);

  // output
  ecrireGraphe(graph);
  parcoursProfond(graph);

  return 0;
}
