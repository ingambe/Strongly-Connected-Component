//
// Created by ingambe on 29/05/18.
//

#include "Gabow.h"

Gabow::Gabow(int nb_noeuds) {
    C = 1;
    num = new int[nb_noeuds];
    placeeCFC = new bool[nb_noeuds];
    for(int i = 0; i < nb_noeuds; i++){
        num[i] = 0;
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
        if(num[*w] == 0){
            visit(graphe, *w);
        } else if(!placeeCFC[*w]){
            while(num[P.top()] > num[*w]){
                P.pop();
            }
        }
    }
    if(v == P.top()){
        int x;
        std::vector<int> tmp;
        if(!placeeCFC[v]) {
            tmp.emplace_back(v);
            placeeCFC[v] = true;
        }
        while(v != S.top()){
            x= S.top();
            if(!placeeCFC[x]) {
                tmp.emplace_back(x);
                placeeCFC[x] = true;
            }
            S.pop();
        }
        CFC->emplace_back(tmp);
        P.pop();
    }
}

std::vector<std::vector<int>> * Gabow::gabow(Graphe *graphe) {
    for(int i = 0; i < graphe->nb_noeuds; i++){
        if(num[i] == 0){
            visit(graphe, i);
        }
    }
    return CFC;
}
