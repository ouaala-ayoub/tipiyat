#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int menu () {
 printf ("\n\n GESTION D'UNE LISTE D'ENTIERS \n\n");

 printf ("1 - Creer une liste\n");
 printf ("2 - Insertion en tete de liste \n");
 printf ("3 - Insertion en fin de liste \n");
 printf ("4 - Retrait en tete de liste \n");
 printf ("5 - Retrait en fin de liste \n");
 printf ("6 - Retrait d un objet a partir de sa reference\n");
 printf ("7 - Afficher les objets de la liste \n");
 printf ("8 - Chercher Un objet \n");
 printf ("9 - Destruction de la liste \n");
 printf ("10 - Fin\n");
 printf ("\n");
 printf ("Votre choix ? ");
 int cod; scanf ("%d", &cod); getchar();
 printf ("\n");
 return cod;
}

int main(){
    IntegerList* list = NULL;
    int choice = menu();
    while(choice != 10){
        switch (choice){
        case 1 :{
            list = malloc(sizeof(IntegerList));
            initList(list);
            break;
        } 
        case 2 : {
            printf("Entrez la valeur que vous voulez ajouter au debut\t");
            int input ;
            scanf("%d", &input);
            insertStart(list, input);
            break;
        }
        case 3:{
            printf("Entrez la valeur que vous voulez ajouter a la fin\t");
            int input ;
            scanf("%d", &input);
            insertEnd(list, input);
            break;
        }
        case 4:{
            printf("suppression de la premiere valeur");
            deleteStart(list);
            break;
        }
        case 5:{
            printf("suppression de la derniere valeur");
            deleteEnd(list);
            break;
        }
        case 6:{
            printf("Entrez la valeur que vous voulez supprimer\t");
            int input ;
            scanf("%d", &input);
            deleteElement(list, input);
            break;
        }
        case 7:{
            printList(list);
            break;
        } 
        case 8:{
            printf("entrez la valeur que vous voulez rechercher\t");
            int input ;
            scanf("%d", &input);
            findElement(list, input);
            break;
        }
        case 9:{
            freeList(list);
            break;
        }
        default:
            printf("choix non valide");
            break;
        }
        choice = menu();
    }
    return 0;
}
