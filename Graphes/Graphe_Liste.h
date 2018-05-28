//
// Created by ingambe on 28/05/18.
//

#ifndef GRAPHES_GRAPHE_LISTE_H
#define GRAPHES_GRAPHE_LISTE_H

#include "Sommet.h"
#include "Graphe.h"

class Graphe_Liste : public Graphe {
private:
    std::vector<Sommet> *tableau_liste_sommet;
public:
    Graphe_Liste(int nb_noeuds);
    Graphe_Liste(Graphe_Liste &a);
    ~Graphe_Liste();
    void ajouterLien(int a, int b);
    std::stack<int> dfs(int debut);
    std::vector<int> voisins(int a);
    Graphe * transposer();
};


#endif //GRAPHES_GRAPHE_LISTE_H
