#include<stdio.h>
#include "header.h"

int main(){

    Noeud *ABR=NULL;

    int n;
    for(int i=0; i<5; i++){
        printf("Entrer[%d] :", i+1);
        scanf("%d", &n);
        ABR = InsererNoeud(ABR, n);
    }
        
    printf("Parcour Infixe\n");
    ParcourInfixe(ABR);
    printf("\n----------------------------------\n");
    printf("Parcour prefixe:\n");

    ParcourPrefixe(ABR);

    printf("\n-----------------------------------------\n");
    printf("Parcour post-Infixe\n");
    ParcourPostInfixe(ABR);

    int stop=1;
    int choix;
    int x;
    Noeud *R;
    
    Noeud *max=maximum(ABR);

    Noeud *min=minimum(ABR);

    int nombreFeuilles=CompterFeuilles(ABR);

    int nombreNoeud =CompterNoeud(ABR);
    
    int nombereHauteur =CompterHauteur(ABR);

    printf("Maximum : %d\n", max->donne);
    printf("----------------------\n");

    printf("Minimum : %d", min->donne);
    printf("---------------------\n");

    printf("Nombre totales de neoud de l'arbre : %d\n", nombreNoeud);
    printf("----------------------------\n");

    printf("Nombre totale d'enfant de l'arbre : %d\n", nombreFeuilles);
    printf("----------------------------------\n");

    printf("La hauteur de l'arbre : %d\n", nombereHauteur);

    
    ABR=SupprimerNoeud(ABR, 10);
    //Apres supression de 10 dans l'arbre
    printf("\n---------------------------------------------------------------\n");
    printf("\tAPRES SUPPRESSION DE 10 ");
    printf("\n-----------------------------------------------------------\n")   ;
    printf("Maximum : %d\n", max->donne);
    printf("----------------------\n");

    printf("Minimum : %d", min->donne);
    printf("---------------------\n");

    printf("Nombre totales de neoud de l'arbre : %d\n", nombreNoeud);
    printf("----------------------------\n");

    printf("Nombre totale d'enfant de l'arbre : %d\n", nombreFeuilles);
    printf("----------------------------------\n");

    printf("La hauteur de l'arbre : %d\n", nombereHauteur);

    


    printf("\n------------------------------------\n");
    while(stop){
        printf("\n1.Continuer\n2.Arreter\n");
        printf("Choix:");
        scanf("%d", &choix);

        if(choix == 1){
            printf("Entrer un nombre entier:");
            scanf("%d", &x);
            R = Recherche(ABR, x);

            if(R !=NULL){
                printf("Element trouvee : %d", R->donne);
            }
            else{
                printf("Element Introuvable dans l'arbre");
            }
        }

        else if(choix==2){
            stop=0;
        }
      
        else{
            printf("Choix invalide !!!\n");
            printf("Entrer un nombre entier:");
            scanf("%d", &x);
            R = Recherche(ABR, x);
            if(R !=NULL){
                printf("Element trouvee : %d", R->donne);
            }
            else{
                printf("Element n'existe pas dans l'arbre.");
            }
        }
    }

    printf("\n-----------------\n");
    printf("Fin du programme\n");

    LibererMemoire(R);
    LibererMemoire(ABR);
    LibererMemoire(max);
    LibererMemoire(min);


    printf("Liberation de la memoire.....\n");
    
    return 0;
}