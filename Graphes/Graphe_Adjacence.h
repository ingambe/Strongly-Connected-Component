//
// Created by ingambe on 30/05/18.
//

#ifndef GRAPHES_GRAPHE_ADJACENCE_H
#define GRAPHES_GRAPHE_ADJACENCE_H


#include "Graphe.h"

class Graphe_Adjacence : public Graphe {
public:
    bool * matrice;
    Graphe_Adjacence(int nb_noeuds);
    Graphe_Adjacence(Graphe_Adjacence &a);
    ~Graphe_Adjacence();
    void ajouterLien(int a, int b);
    std::stack<int> dfs(int debut, bool * visitee);
    std::vector<int> voisins(int a);
    Graphe * transposer();
    void supprimerSommet(int sommet);
};


#endif //GRAPHES_GRAPHE_ADJACENCE_H
