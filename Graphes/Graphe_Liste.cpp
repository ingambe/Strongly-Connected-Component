//
// Created by ingambe on 28/05/18.
//

#include <algorithm>
#include "Graphe_Liste.h"

Graphe_Liste::Graphe_Liste(int nb_noeuds) {
    this->nb_noeuds = nb_noeuds;
    this->tableau_liste_sommet = new std::vector<int>[nb_noeuds];
}

Graphe_Liste::Graphe_Liste(Graphe_Liste &a) {
    this->nb_noeuds = a.nb_noeuds;
    this->tableau_liste_sommet = new std::vector<int>[nb_noeuds];
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

std::stack<int> Graphe_Liste::dfs(int debut, bool * visitee) {
    std::stack<int> resultat;
    std::stack<int> pile;
    pile.push(debut);
    visitee[debut] = true;
    while(!pile.empty()){
        int x = pile.top();
        pile.pop();
        resultat.push(x);
        std::vector<int> lesVoisins = voisins(x);
        for(auto y = lesVoisins.begin(); y != lesVoisins.end(); y++){
            if(!visitee[*y]) {
                visitee[*y] = true;
                pile.push(*y);
            }
        }
    }
    return resultat;
}

std::vector<int> Graphe_Liste::voisins(int a) {
    return tableau_liste_sommet[a];
}

Graphe * Graphe_Liste::transposer() {
    Graphe * resultat = new Graphe_Liste(nb_noeuds);
    for(int i = 0; i < nb_noeuds; i++){
        std::vector<int> voisin = this->voisins(i);
        for(auto j = voisin.begin(); j != voisin.end(); j++){
            resultat->ajouterLien(*j,i);
        }
    }
    return resultat;
}

void Graphe_Liste::supprimerSommet(int sommet) {
    for(int i = 0; i < nb_noeuds; i++){
        if(i == sommet){
            tableau_liste_sommet[i].clear();
        } else {
            tableau_liste_sommet[i].erase(std::remove(tableau_liste_sommet[i].begin(), tableau_liste_sommet[i].end(), sommet), tableau_liste_sommet[i].end());
        }
    }
}
