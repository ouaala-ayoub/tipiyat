// equivalent of listPerssone.c

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Personne *getUserInput()
{
    char nom[16], prenom[16];
    printf("Entrez le nom \t");
    scanf("%s", nom);
    printf("Entrez le prenom \t");
    scanf("%s", prenom);
    return creerPersonne(nom, prenom);
}

int menu()
{
    printf("\n\nGESTION D'UNE LISTE DE PERSONNES\n\n");
    printf("0 - Fin\n");
    printf("1 - Insertion en tete de liste\n");
    printf("2 - Insertion en fin de liste\n");
    printf("3 - Retrait en tete de liste\n");
    printf("4 - Retrait en fin de liste\n");
    printf("5 - Retrait d'un element à partir de son nom\n");
    printf("6 - Parcours de la liste\n");
    printf("7 - Recherche d'un element a partir de son nom\n");
    printf("8 - Destruction de la liste\n");
    printf("\n");
    printf("Votre choix ? ");
    int cod;
    scanf("%d", &cod);
    printf("\n");
    return cod;
}

int main()
{
    List *list = creerList(ecrirePersonne, comparerPersonnes);

    int choice = menu();
    while (choice != 0)
    {
        switch (choice)
        {
        case 0: {
            printf("Fin");
            break;
        }
        case 1:{
            Personne *input = getUserInput();
            insererEnTete(list, input);
            break;
        }
        case 2:{
            Personne *input = getUserInput();
            insererALafin(list, input);
            break;
        }
        
        case 3:{
            Object* suprimme = supprimerPremier(list);
            if(suprimme != NULL){
                printf("supprimee premier avec success");
            } else{
                printf("erreur de la suppression");
            }
            break;
        }
        case 4:{
            Object* suprimme = supprimerDernier(list);
            if(suprimme != NULL){
                printf("supprimee dernier avec success");
            } else{
                printf("erreur de la suppression");
            }
            break;
        }
        case 5:{
            printf("entrez le nom que vous voulez supprimer\t");
            char input[16];
            scanf("%s", input);
            supprimerElement(list, creerPersonne(input, ""));
            printf("element suprimmee avec success");
            break;
        }
        case 6:{
            printList(list);
            break;
        } 
        case 7:{
            printf("entrez le nom cherchee\t");
            char input[16];
            scanf("%s", input);
            Element *found = chercherElement(list, creerPersonne(input, ""));
            if (found != NULL){
                printf("trouve %s", list->afficher(found->reference));
            }
            break;
        } 
        default:
            printf("choix invalide");
            break;
        }
        
        choice = menu();
    }
    getchar();
    return 0;
}
