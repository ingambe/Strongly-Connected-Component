//
// Created by ingambe on 29/05/18.
//

#include "GraphGenerator.h"
#include "Graphes/Graphe_Liste.h"
#include "Graphes/Graphe_Adjacence.h"

Graphe *GraphGenerator::genererGrapheListe(int nb_lien) {
    Graphe * graphe = new Graphe_Liste(NB_NOEUD);
    for(int noeud = 0; noeud < NB_NOEUD; noeud++){
        for(int i = 0; i < nb_lien / NB_NOEUD; i++){
            graphe->ajouterLien(noeud, (noeud + 1 + i) % NB_NOEUD);
        }
    }
    return graphe;
}

Graphe *GraphGenerator::genererGrapheAdjacence(int nb_lien) {
    Graphe * graphe = new Graphe_Adjacence(NB_NOEUD);
    for(int noeud = 0; noeud < NB_NOEUD; noeud++){
        for(int i = 0; i < nb_lien / NB_NOEUD; i++){
            graphe->ajouterLien(noeud, (noeud + 1 + i) % NB_NOEUD);
        }
    }
    return graphe;
}
