//
// Created by ingambe on 29/05/18.
//

#ifndef GRAPHES_GRAPHGENERATOR_H
#define GRAPHES_GRAPHGENERATOR_H

#define NB_NOEUD 100

#include "Graphes/Graphe.h"

class GraphGenerator {
public:
    static Graphe * genererGrapheListe(int nb_lien);
    static Graphe * genererGrapheAdjacence(int nb_lien);
};


#endif //GRAPHES_GRAPHGENERATOR_H
