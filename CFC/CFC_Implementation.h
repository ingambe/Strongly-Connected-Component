//
// Created by ingambe on 09/06/18.
//

#ifndef GRAPHES_CFC_H
#define GRAPHES_CFC_H

#include <vector>
#include <set>
#include "../Graphes/Graphe.h"

class CFC_Implementation {
public:
    virtual std::vector<std::set<int>> * CFC(Graphe * graphe) = 0;
};


#endif //GRAPHES_CFC_H
