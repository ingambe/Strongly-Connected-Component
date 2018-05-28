#include <iostream>
#include <stack>
#include "Graphes/Graphe_Liste.h"

void afficher_pile(std::stack<int> pile){
    while(!pile.empty()){
        std::cout << pile.top() << " ";
        pile.pop();
    }
    std::cout << std::endl;
}

/**
 * Represente l'arbre page 83 des slides
 */
void test_DFS_liste(){
    Graphe_Liste graphe(12);
    graphe.ajouterLien(0,1);
    graphe.ajouterLien(0,2);
    graphe.ajouterLien(0,3);
    graphe.ajouterLien(1,4);
    graphe.ajouterLien(1,5);
    graphe.ajouterLien(4,8);
    graphe.ajouterLien(4,9);
    graphe.ajouterLien(3,6);
    graphe.ajouterLien(3,7);
    graphe.ajouterLien(6,10);
    graphe.ajouterLien(6,11);
    std::stack<int> dfs = graphe.dfs(0);
    std::cout << "La taille doit etre de 12 : " << dfs.size() << std::endl;
    afficher_pile(dfs);
}


int main() {
    test_DFS_liste();
    return 0;
}