//
// Created by ingambe on 28/05/18.
//

#include "Kosaraju.h"

std::stack<int> supprimerElementPile(std::stack<int> pile, int element){
    std::stack<int> tmp;
    while(!pile.empty()){
        int top = pile.top();
        pile.pop();
        if(top != element){
            tmp.push(top);
        }
    }
    return tmp;
}

std::vector<std::set<int>> * Kosaraju::CFC(Graphe * graphe) {
    std::vector<std::set<int>> * CFC = new std::vector<std::set<int>>();
    std::stack<int> pile;
    bool parcouru[graphe->getNbNoeuds()] = {0};
    bool visitee[graphe->nb_noeuds] = {0};
    int aParcourir = 0;
    while(pile.size() < graphe->getNbNoeuds()){
        for(int i = 0; i < graphe->getNbNoeuds(); i++){
            if(parcouru[i] == 0){
                parcouru[i] = 1;
                aParcourir = i;
                break;
            }
        }
        std::stack<int> dfs = graphe->dfs(aParcourir, visitee);
        while(!dfs.empty()){
            int tmp = dfs.top();
            dfs.pop();
            pile.push(tmp);
            parcouru[tmp] = 1;
        }
    }

    Graphe * transpose = graphe->transposer();

    for(int i = 0; i < graphe->nb_noeuds; i++){
        visitee[i] = false;
    }
    while(!pile.empty()){
        int v = pile.top();
        pile.pop();
        std::stack<int> dfs = transpose->dfs(v, visitee);
        std::set<int> aPush;
        aPush.insert(v);
        for (int i = 0; i < dfs.size(); i++) {
            int tmp = dfs.top();
            dfs.pop();
            aPush.insert(tmp);
        }
        if(!aPush.empty()) {
            CFC->emplace_back(aPush);
            for(auto i = aPush.begin(); i != aPush.end(); i++){
                pile = supprimerElementPile(pile, *i);
                transpose->supprimerSommet(*i);
            }
        }
    }
    return CFC;
}
