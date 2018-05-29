//
// Created by ingambe on 28/05/18.
//

#include "Kosaraju.h"

std::stack<int> supprimerElementPile(std::stack<int> pile, int element){
    std::stack<int> resultat;
    while(!pile.empty()){
        int top = pile.top();
        pile.pop();
        if(top != element){
            resultat.push(top);
        }
    }
    return resultat;
}

std::vector<std::vector<int>> Kosaraju::kosaraju(Graphe * graphe) {
    std::vector<std::vector<int>> CFC;
    std::stack<int> pile;
    bool parcouru[graphe->getNbNoeuds()] = {0};
    int aParcourir = 0;
    while(pile.size() < graphe->getNbNoeuds()){
        for(int i = 0; i < graphe->getNbNoeuds(); i++){
            if(parcouru[i] == 0){
                parcouru[i] = 1;
                aParcourir = i;
                break;
            }
        }
        std::stack<int> dfs = graphe->dfs(aParcourir);
        while(!dfs.empty()){
            int tmp = dfs.top();
            dfs.pop();
            pile.push(tmp);
            parcouru[tmp] = 1;
        }
    }

    Graphe * transpose = graphe->transposer();
    bool element_suppr[graphe->nb_noeuds] = {0};
    while(!pile.empty()){
        int v = pile.top();
        pile.pop();
        std::stack<int> dfs = transpose->dfs(v);
        std::vector<int> aPush;
        if(!element_suppr[v]) {
            aPush.push_back(v);
            element_suppr[v] = true;
        }
        for (int i = 0; i < dfs.size(); i++) {
            int tmp = dfs.top();
            dfs.pop();
            if(!element_suppr[tmp]) {
                aPush.emplace_back(tmp);
                pile = supprimerElementPile(pile, tmp);
                element_suppr[tmp] = true;
            }
        }
        if(!aPush.empty()) {
            CFC.emplace_back(aPush);
        }
    }
    return CFC;
}