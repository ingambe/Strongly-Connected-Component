#include <iostream>
#include <stack>
#include "Graphes/Graphe_Liste.h"
#include "Kosaraju.h"

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

/**
 * Graphe page 101
 */
void test_Kosaraju_liste(){
    Graphe_Liste * graphe = new Graphe_Liste(8);
    graphe->ajouterLien(0,1);
    graphe->ajouterLien(1,2);
    graphe->ajouterLien(1,4);
    graphe->ajouterLien(1,5);
    graphe->ajouterLien(2,3);
    graphe->ajouterLien(2,6);
    graphe->ajouterLien(3,2);
    graphe->ajouterLien(3,7);
    graphe->ajouterLien(4,0);
    graphe->ajouterLien(4,5);
    graphe->ajouterLien(5,6);
    graphe->ajouterLien(6,5);
    graphe->ajouterLien(7,3);
    graphe->ajouterLien(7,6);
    std::vector<std::vector<int>> kosaraju = Kosaraju::kosaraju(graphe);
    std::cout << "nombre de CFC : " << kosaraju.size() << std::endl;
    for(int i = 0; i < kosaraju.size(); i++){
        std::cout << "CFC numero " << i << std::endl;
    }
}


int main() {
    test_DFS_liste();
    test_Kosaraju_liste();
    return 0;
}