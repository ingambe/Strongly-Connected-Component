//
// Created by ingambe on 29/05/18.
//

#include "Tarjan.h"

int min(int a, int b){
    if(a <= b){
        return a;
    }
    return b;
}

std::vector<std::vector<int>> * Tarjan::tarjan(Graphe *graphe) {
    num = 0;
    P = new std::stack<int>();
    numAccessible = new int[graphe->nb_noeuds];
    numSommet = new int[graphe->nb_noeuds];
    dansP = new bool[graphe->nb_noeuds];
    for(int i = 0; i < graphe->nb_noeuds; i++){
        numAccessible[i] = -1;
        numSommet[i] = -1;
        dansP[i] = false;
    }
    partition = new std::vector<std::vector<int>>();
    for(int i = 0; i < graphe->nb_noeuds; i++){
        if(numSommet[i] == -1){
            parcours(graphe, i);
        }
    }
    return partition;
}

void Tarjan::parcours(Graphe *graphe, int v) {
    numSommet[v] = num;
    numAccessible[v] = num;
    num++;
    P->push(v);
    dansP[v] = true;
    std::vector<int> voisins = graphe->voisins(v);
    for(auto i = voisins.begin(); i != voisins.end(); i++){
        if(numSommet[*i] == -1){
            parcours(graphe, *i);
            numAccessible[v] = min(numAccessible[v], numAccessible[*i]);
        } else if(dansP[numAccessible[*i]]){
            numAccessible[v] = min(numAccessible[v], numSommet[*i]);
        }
    }
    if(numAccessible[v] == numSommet[v]){
        std::vector<int> C;
        int w;
        do {
            w = P->top();
            P->pop();
            dansP[w] = false;
            C.emplace_back(w);
        }while(w!=v);
        partition->emplace_back(C);
    }
}
