#include<stdio.h>
#include<stdlib.h>



typedef struct Noeud{
    int valeur;
    struct Noeud  *gauche;
    struct Noeud *droit;
}Noeud;


//CREATION  D'UN NOUVEAU NOEUD FEUILLE

Noeud *CreerNoeud(int donne){
    Noeud *nouveau =(Noeud*)malloc(sizeof(Noeud));
    if(nouveau !=NULL){
        print("Erreur  de malloc");
        exit(1);
    }
    nouveau->valeur=donne;
    nouveau->gauche=NULL;
    nouveau->droit=NULL;
    return nouveau; 
}


// ----------------------------------------------------
//                A- PARCOUR EN PROFONDEUR 
// -------------------------------------------------
// //   ==>> Les parcours d'un arbre binaire
//  1- Parcour preordre(racine -> gauche -> droit)== parcour Prefix)

void ParcourPrefixe(Noeud *racine){
    if (racine !=NULL){
        printf("%d", racine->valeur);  //Racine
        ParcourPrefixe(racine->gauche);  //Gauche
        ParcourPrefixe(racine->droit);  //droit
    }
}

// 2-- Parcour Infixe(inordre)==(Gauche->racine->Droit)
// Particulierement important :Applique a un ABR, il donne
// les valeurs triees par ordre 

void ParcourInfix(Noeud *racine){
    if(racine !=NULL){
        ParcourInfix(racine->gauche);
        printf("%d", racine->valeur);
        ParcourInfix(racine->droit);
    }
}

// 3-Parcour Post-Infix(Gauche->droit->racine)=(POSTORDRE)
// Utile pour liberer la memoire d'un arbre ou evaluer une eexpression

void ParcourPostordre(Noeud *racine){
    if(racine !=NULL){
        ParcourPostordre(racine->gauche);
        ParcourPostordre(racine->droit);
        printf("%d", racine->valeur);
    }
}

   
// -----------------------------------------------------
//                 PARCOUR EN LARGEUR
// ----------------------------------------------------
// Ici on visite les noeud par niveau, a l'aide d'une file (FIFO)?



//creation de la stricture file 
typedef struct Filer {
    Noeud *donnes[1000];
    int debut;
    int fin;
}File;


// void InitFile(File *f){
//     f->debut=0;
//     f->fin=0;
// }


// int fileVide(File *f){
//     return f->debut = f->fin;
// }

void enfiler(File *f, Noeud * racine){
    
}
