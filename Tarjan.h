//
// Created by ingambe on 29/05/18.
//

#ifndef GRAPHES_TARJAN_H
#define GRAPHES_TARJAN_H


#include "Graphes/Graphe.h"

class Tarjan {
public:
    int num;
    std::stack<int> * P;
    std::vector<std::vector<int>> * partition;
    bool * dansP;
    int * numSommet;
    int * numAccessible;
    std::vector<std::vector<int>> * tarjan(Graphe * graphe);
    void parcours(Graphe * graphe, int v);
};


#endif //GRAPHES_TARJAN_H
