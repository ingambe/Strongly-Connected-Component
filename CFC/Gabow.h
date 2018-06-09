//
// Created by ingambe on 29/05/18.
//

#ifndef GRAPHES_GABOW_H
#define GRAPHES_GABOW_H

#include "../Graphes/Graphe.h"
#include "CFC_Implementation.h"

class Gabow : public CFC_Implementation {
public:
    int C;
    int * num;
    bool * placeeCFC;
    std::stack<int> S;
    std::stack<int> P;
    std::vector<std::set<int>> * CFC_vector;
    Gabow(int nb_noeuds);
    ~Gabow();
    std::vector<std::set<int>> * CFC(Graphe * graphe);
    void visit(Graphe * graphe, int v);
};


#endif //GRAPHES_GABOW_H
