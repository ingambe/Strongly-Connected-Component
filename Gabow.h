//
// Created by ingambe on 29/05/18.
//

#ifndef GRAPHES_GABOW_H
#define GRAPHES_GABOW_H


#include <vector>
#include "Graphes/Graphe.h"

class Gabow {
public:
    int C;
    int * num;
    bool * placeeCFC;
    std::stack<int> S;
    std::stack<int> P;
    std::vector<std::vector<int>> * CFC;
    Gabow(int nb_noeuds);
    ~Gabow();
    std::vector<std::vector<int>> * gabow(Graphe * graphe);
    void visit(Graphe * graphe, int v);
};


#endif //GRAPHES_GABOW_H
