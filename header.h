# ifndef HEADER_H
# define HEADER_H

//Structure arbre
typedef struct Noeud{
    int donne;
    struct  Noeud *gauche;
    struct  Noeud *droit;
}Noeud;


//Creation d'un elemnent 
Noeud *CreerNoeud(int valeur);

Noeud *InsererNoeud(Noeud *racine, int valeur);

void ParcourInfixe(Noeud *racine);

void ParcourPrefixe(Noeud *racine);

void ParcourPostInfixe(Noeud *racine);

Noeud *Recherche(Noeud *racine, int valeur);

Noeud *minimum(Noeud * racine);

Noeud *maximum(Noeud *racine);

int CompterNoeud(Noeud *racine);

int CompterFeuilles(Noeud *racine);

int CompterHauteur(Noeud *racine);

Noeud *SupprimerNoeud(Noeud *racine, int valeur);

void LibererMemoire(Noeud *racine);

# endif