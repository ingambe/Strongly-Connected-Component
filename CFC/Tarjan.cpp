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

Tarjan::Tarjan() {
    P = new std::stack<int>();
    num = 0;
    partition = new std::vector<std::set<int>>();
}

Tarjan::~Tarjan() {
    if(P!=NULL){
        delete[] P;
    }
    P = NULL;
    if(numAccessible != NULL){
        delete[] numAccessible;
    }
    numAccessible = NULL;
    if(numSommet != NULL){
        delete[] numSommet;
    }
    numSommet = NULL;
    if(dansP != NULL){
        delete[] dansP;
    }
    dansP = NULL;
    if(partition != NULL){
        delete partition;
    }
    partition = NULL;
}

std::vector<std::set<int>> * Tarjan::CFC(Graphe *graphe) {
    numAccessible = new int[graphe->nb_noeuds];
    numSommet = new int[graphe->nb_noeuds];
    dansP = new bool[graphe->nb_noeuds];
    for(int i = 0; i < graphe->nb_noeuds; i++){
        numAccessible[i] = -1;
        numSommet[i] = -1;
        dansP[i] = false;
    }
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
        std::set<int> C;
        int w;
        do {
            w = P->top();
            P->pop();
            dansP[w] = false;
            C.insert(w);
        }while(w!=v);
        partition->emplace_back(C);
    }
}
