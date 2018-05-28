//
// Created by ingambe on 28/05/18.
//

#include "Graphe_Liste.h"

Graphe_Liste::Graphe_Liste(int nb_noeuds) {
    this->nb_noeuds = nb_noeuds;
    this->tableau_liste_sommet = new std::vector<Sommet>[nb_noeuds];
}

Graphe_Liste::Graphe_Liste(Graphe_Liste &a) {
    this->nb_noeuds = a.nb_noeuds;
    this->tableau_liste_sommet = new std::vector<Sommet>[nb_noeuds];
    for(int i = 0; i < nb_noeuds; i++){
        for(auto j = a.tableau_liste_sommet[i].begin(); j != a.tableau_liste_sommet[i].end(); j++){
            tableau_liste_sommet[i].push_back(*j);
        }
    }
}

Graphe_Liste::~Graphe_Liste() {
    if(this->tableau_liste_sommet != NULL){
        delete[] tableau_liste_sommet;
    }
    tableau_liste_sommet = NULL;
}

void Graphe_Liste::ajouterLien(int a, int b) {
    tableau_liste_sommet[a].emplace_back(b);
}

std::stack<int> Graphe_Liste::dfs(int debut) {
    std::stack<int> resultat;
    bool visitee[nb_noeuds];
    for(int i = 0; i < nb_noeuds; i++){
        visitee[i] = false;
    }
    std::stack<int> pile;
    pile.push(debut);
    visitee[debut] = true;
    while(!pile.empty()){
        int x = pile.top();
        pile.pop();
        resultat.push(x);
        for(auto y = tableau_liste_sommet[x].begin(); y != tableau_liste_sommet[x].end(); y++){
            if(!visitee[y->id]){
                visitee[y->id] = true;
                pile.push(y->id);
            }
            //else pile.pop();
        }
    }
    return resultat;
}

std::vector<int> Graphe_Liste::voisins(int a) {
    std::vector<int> resultat;
    for(auto i = tableau_liste_sommet[a].begin(); i != tableau_liste_sommet[a].end(); i++){
        resultat.emplace_back(i->id);
    }
    return resultat;
}

Graphe * Graphe_Liste::transposer() {
    Graphe_Liste * resultat = new Graphe_Liste(nb_noeuds);
    for(int i = 0; i < nb_noeuds; i++){
        std::vector<int> voisinI = voisins(i);
        for(auto j = voisinI.begin(); j != voisinI.end(); j++){
            resultat->tableau_liste_sommet[i].emplace_back(*j);
        }
    }
    return resultat;
}
