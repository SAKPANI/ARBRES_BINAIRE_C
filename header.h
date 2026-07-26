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

Noeud *SupprimerNoeud(Noeud *racine, int valeur);


# endif