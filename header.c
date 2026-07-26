#include<stdio.h>
#include<stdlib.h>
#include "header.h"

Noeud *CreerNoeud(int valeur){
    Noeud *nouveau=(Noeud*)malloc(sizeof(Noeud));
    if(nouveau == NULL){
        printf("Erreur malloc !!");
        exit(1);
    }
    nouveau->donne = valeur;
    nouveau->gauche=NULL;
    nouveau->droit=NULL;
    return nouveau;
}



//Insertion d'un element dans un arbres binaire
Noeud *InsererNoeud(Noeud * racine, int valeur){
    if(racine==NULL){
        return CreerNoeud(valeur);
    }
    else if (valeur <racine->donne){
        racine->gauche=InsererNoeud(racine->gauche, valeur);
    }
    else if(valeur > racine->donne){
        racine->droit=InsererNoeud(racine->droit, valeur);
    }
    return racine;
}


/// LES DIFFERENTES TYPE DE PARCOURS D'UN ARBRE BINAIRES

void ParcourInfixe(Noeud *racine){  // inorder G->R->D
    if(racine !=NULL){
        ParcourInfixe(racine->gauche);
        printf("%d ->", racine->donne);
        ParcourInfixe(racine->droit);
    }
}


//Parcour-Prefixe
void ParcourPrefixe(Noeud *racine){  //Preorder(G->R->D)
    if (racine !=NULL){
        printf("%d ->", racine->donne);
        ParcourPrefixe(racine->gauche);
        ParcourPrefixe(racine->droit);
    }
}


//Parcour post-Infixe
void ParcourPostInfixe(Noeud * racine){ // G-D-R
    if(racine !=NULL){
        ParcourPostInfixe(racine->gauche);
        ParcourPostInfixe(racine->droit);
        printf("%d ->", racine->donne);
    }
}


Noeud *Recherche(Noeud *racine , int valeur){

    if(racine == NULL){
        return NULL;
    }

    else if(valeur==racine->donne){
        return racine;
    }

    else if(valeur < racine->donne){
       return Recherche(racine->gauche, valeur);
    }

    else if(valeur>racine->donne){
        return Recherche(racine->droit, valeur);
    }
    return NULL;
}