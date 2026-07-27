#include<stdio.h>
#include<stdlib.h>
#include "header.h"


//Creation d'un noeud 
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

//RECHERCHE D'UN ELEMNT 
Noeud *Recherche(Noeud *racine, int valeur){
    if(racine == NULL){
        return NULL;
    }
    else if(racine->donne == valeur){
        return racine;
    }
    else if(valeur > racine->donne){
        return Recherche(racine->droit, valeur);
    }
    else if(valeur < racine->donne){
        return Recherche(racine->droit, valeur);
    }
    return NULL;
}


//minimum
Noeud *minimum(Noeud *racine){
    if(racine == NULL || racine->gauche==NULL){
        return racine;
    }
    else{
        return minimum(racine->gauche);
    }
}


//maximum
Noeud *maximum(Noeud *racine){
    if(racine == NULL || racine->droit == NULL){
        return racine;
    }
    else{
        return maximum(racine->droit);
    }
}


//compteur du noeud de l'arbres
int CompterNoeud(Noeud *racine){
    if(racine == NULL){
        return 0;
    }
    else{
        return 1+( CompterNoeud(racine->gauche) + CompterNoeud(racine->droit));
    }
}


//Compter Feuilles 
int CompterFeuilles(Noeud *racine){
    if(racine == NULL){
        return 0;
    }
    else{
        return CompterFeuilles(racine->gauche) + CompterFeuilles(racine->droit);
    }
}


//CompterHauteur
int CompterHauteur(Noeud *racine){
    if(racine == NULL){
        return -1;
    }
    else{
        int hg=CompterHauteur(racine->gauche);
        int hd=CompterHauteur(racine->droit);
        return 1+ (hg > hd ? hg : hd);
    }
}


//Supression 
Noeud * SupprimerNoeud(Noeud *racine, int valeur){
    if(racine == NULL){
        return NULL;
    }
    else if(valeur < racine->donne){
        racine->gauche=SupprimerNoeud(racine->gauche, valeur);
    }

    else if(valeur > racine->donne){
        racine->droit = SupprimerNoeud(racine->droit, valeur);
    }

    else{

        if(racine->gauche == NULL &&  racine->droit==NULL){
            free(racine);
            return NULL;
        }

        else if(racine->gauche== NULL && racine->droit !=NULL){
            Noeud *temp=racine->droit;
            free(racine);
            return temp;
        }

        else if (racine->gauche !=NULL && racine->droit==NULL){
            Noeud *temp=racine->gauche;
            free(racine);
            return temp;
        }
        
        //Avec deux enfants
        else if(racine->gauche !=NULL && racine->droit){
            Noeud *Successeur =minimum(racine->droit);
            racine->donne = Successeur->donne;
            racine->droit =SupprimerNoeud(racine->droit, Successeur->donne);
        }
    }
    return racine;
}


void LibererMemoire(Noeud * racine){
    if(racine == NULL){
        return ;
    LibererMemoire(racine->gauche);
    LibererMemoire(racine->droit);
    free(racine);
    }
}