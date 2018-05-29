//
// Created by ingambe on 29/05/18.
//

#include "Gabow.h"

Gabow::Gabow(int nb_noeuds) {
    C = 0;
    num = new int[nb_noeuds];
    placeeCFC = new bool[nb_noeuds];
    for(int i = 0; i < nb_noeuds; i++){
        num[i] = -1;
        placeeCFC[i] = false;
    }
    CFC = new std::vector<std::vector<int>>();
}

Gabow::~Gabow() {
    if(num != NULL){
        delete[] num;
    }
    num = NULL;
}

void Gabow::visit(Graphe * graphe, int v) {
    num[v] = C;
    C++;
    S.push(v);
    P.push(v);
    std::vector<int> vosinsV = graphe->voisins(v);
    for(auto w = vosinsV.begin(); w != vosinsV.end(); w++){
        if(num[*w] == -1){
            visit(graphe, *w);
        } else if(!placeeCFC[*w]){
            while(num[P.top()] > num[*w]){
                P.pop();
            }
        }
    }
    if(v == P.top()){
        std::vector<int> tmp;
        while(v != S.top()){
            tmp.emplace_back(S.top());
            placeeCFC[S.top()] = true;
            S.pop();
        }
        CFC->emplace_back(tmp);
        P.pop();
    }
}

std::vector<std::vector<int>> * Gabow::gabow(Graphe *graphe) {
    for(int i = 0; i < graphe->nb_noeuds; i++){
        if(num[i] == -1){
            visit(graphe, i);
        }
    }
    return CFC;
}
