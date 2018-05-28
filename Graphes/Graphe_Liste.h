//
// Created by ingambe on 28/05/18.
//

#ifndef GRAPHES_GRAPHE_LISTE_H
#define GRAPHES_GRAPHE_LISTE_H


#include <vector>
#include <stack>
#include "Sommet.h"

class Graphe_Liste {
private:
    int nb_noeuds;
    std::vector<Sommet> *tableau_liste_sommet;
public:
    Graphe_Liste(int nb_noeuds);
    Graphe_Liste(Graphe_Liste &a);
    ~Graphe_Liste();
    void ajouterLien(int a, int b);
    std::stack<int> dfs(int debut);
};


#endif //GRAPHES_GRAPHE_LISTE_H
