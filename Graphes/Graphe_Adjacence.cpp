//
// Created by ingambe on 30/05/18.
//

#include "Graphe_Adjacence.h"

Graphe_Adjacence::Graphe_Adjacence(int nb_noeuds) {
    this->nb_noeuds = nb_noeuds;
    this->matrice = new bool[nb_noeuds * nb_noeuds];
    for(int i = 0; i < nb_noeuds; i++){
        for(int j = 0; j < nb_noeuds; j++){
            matrice[(i * nb_noeuds) + j] = false;
        }
    }
}

Graphe_Adjacence::Graphe_Adjacence(Graphe_Adjacence &a) {
    this->nb_noeuds = a.nb_noeuds;
    this->matrice = new bool[nb_noeuds * nb_noeuds];
    for(int i = 0; i < nb_noeuds; i++){
        for(int j = 0; j < nb_noeuds; j++){
            matrice[(i * nb_noeuds) + j] = a.matrice[(i * nb_noeuds) + j];
        }
    }
}

Graphe_Adjacence::~Graphe_Adjacence() {
    if(matrice != NULL){
        delete[] matrice;
    }
    matrice = NULL;
}

void Graphe_Adjacence::ajouterLien(int a, int b) {
    matrice[(a * nb_noeuds) + b] = true;
}

std::stack<int> Graphe_Adjacence::dfs(int debut) {
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

std::vector<int> Graphe_Adjacence::voisins(int a) {
    std::vector<int> lesVoisins;
    for(int i = 0; i < nb_noeuds; i++){
        if(matrice[(a * nb_noeuds) + i]){
            lesVoisins.emplace_back(i);
        }
    }
    return lesVoisins;
}

Graphe *Graphe_Adjacence::transposer() {
    Graphe_Adjacence * transpose = new Graphe_Adjacence(nb_noeuds);
    for(int i = 0; i < nb_noeuds; i++){
        for(int j = 0; j < nb_noeuds; j++){
            transpose->matrice[(i * nb_noeuds) + j] = matrice[(j * nb_noeuds) + i];
        }
    }
    return transpose;
}

void Graphe_Adjacence::supprimerSommet(int sommet) {
    for(int i = 0; i < nb_noeuds; i++){
        matrice[(i * nb_noeuds) + sommet] = false;
    }
    for(int j = 0; j < nb_noeuds; j++){
        matrice[(sommet * nb_noeuds) + j] = false;
    }
}