//
// Created by ingambe on 28/05/18.
//

#include "Kosaraju.h"

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
    // permet d'eviter l'operation complexe de supprimer un element de la pile de la DFS
    bool aSupprS[graphe->nb_noeuds] = {0};
    while(!pile.empty()){
        int v = pile.top();
        pile.pop();
        if(!aSupprS[v]) {
            std::stack<int> dfs = transpose->dfs(v);
            std::vector<int> aPush;
            for (int i = 0; i < dfs.size(); i++) {
                int tmp = dfs.top();
                dfs.pop();
                aSupprS[tmp] = true;
                aPush.emplace_back(tmp);
            }
            CFC.emplace_back(aPush);
        }
    }
    return CFC;
}
