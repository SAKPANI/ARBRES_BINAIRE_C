#include<stdio.h>
#include "header.h"

int main(){

    Noeud *ABR=NULL;

    ABR = InsererNoeud(ABR, 20);
    ABR = InsererNoeud(ABR, 50);
    ABR = InsererNoeud(ABR, 68);
    ABR = InsererNoeud(ABR, 98);
    ABR = InsererNoeud(ABR, 65);
    ABR = InsererNoeud(ABR, 1100);
        
    printf("Parcour Infixe\n");
    ParcourInfixe(ABR);
    printf("\n----------------------------------\n");
    printf("Parcour prefixe:\n");

    ParcourPrefixe(ABR);

    printf("\n-----------------------------------------\n");
    printf("Parcour post-Infixe\n");
    ParcourPostInfixe(ABR);
    
    return 0;
}