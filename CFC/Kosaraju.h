//
// Created by ingambe on 28/05/18.
//

#ifndef GRAPHES_KOSARAJU_H
#define GRAPHES_KOSARAJU_H


#include "../Graphes/Graphe.h"
#include "CFC_Implementation.h"

class Kosaraju : public CFC_Implementation {
public:
    std::vector<std::set<int>> * CFC(Graphe * graphe);
};


#endif //GRAPHES_KOSARAJU_H
