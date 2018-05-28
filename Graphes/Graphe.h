//
// Created by ingambe on 28/05/18.
//

#ifndef GRAPHES_GRAPHE_H
#define GRAPHES_GRAPHE_H


#include <stack>
#include <vector>

class Graphe {
public:
    int nb_noeuds;
    virtual void ajouterLien(int a, int b) = 0;
    virtual std::stack<int> dfs(int debut) = 0;
    virtual std::vector<int> voisins(int a) = 0;
    int getNbNoeuds();
    virtual Graphe * transposer() = 0;
};


#endif //GRAPHES_GRAPHE_H
