//
// Created by ingambe on 29/05/18.
//

#ifndef GRAPHES_TARJAN_H
#define GRAPHES_TARJAN_H


#include "../Graphes/Graphe.h"
#include "CFC_Implementation.h"

class Tarjan : public CFC_Implementation {
public:
    Tarjan();
    ~Tarjan();
    int num;
    std::stack<int> * P;
    std::vector<std::set<int>> * partition;
    bool * dansP;
    int * numSommet;
    int * numAccessible;
    std::vector<std::set<int>> * CFC(Graphe * graphe);
    void parcours(Graphe * graphe, int v);
};


#endif //GRAPHES_TARJAN_H
