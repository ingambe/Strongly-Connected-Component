#include <iostream>
#include <stack>
#include <ctime>
#include "Graphes/Graphe_Liste.h"
#include "Kosaraju.h"
#include "Tarjan.h"
#include "Gabow.h"
#include "GraphGenerator.h"

void afficher_pile(std::stack<int> pile){
    while(!pile.empty()){
        std::cout << pile.top() << " ";
        pile.pop();
    }
    std::cout << std::endl;
}


/**
 * FONCTIONS DE TESTS
 **/


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
 * test dfs kosaraju
 */
void test_dfs_kosaraju(){

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
    std::stack<int> dfs = graphe->dfs(0);
    std::cout << "La taille doit etre de 8 : " << dfs.size() << std::endl;
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
    int compteur = 0;
    for(auto i = kosaraju.begin(); i != kosaraju.end(); i++){
        std::cout << "CFC numero " << compteur << std::endl;
        compteur++;
        for(auto j = i->begin(); j!= i->end(); *j++){
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
}

void test_transpose(){
    Graphe_Liste * graphe = new Graphe_Liste(3);
    graphe->ajouterLien(0,1);
    graphe->ajouterLien(1,2);
    Graphe * transpose = graphe->transposer();
    for(int i = 0; i < transpose->nb_noeuds; i++){
        std::vector<int> voisin = transpose->voisins(i);
        std::cout << "voisin de " << i << " : ";
        for(auto j = voisin.begin() ; j != voisin.end(); j++){
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Graphe page 101
 */
void test_Tarjan_liste(){
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
    Tarjan * tarjan = new Tarjan();
    std::vector<std::vector<int>> * resultat = tarjan->tarjan(graphe);
    std::cout << "nombre de CFC : " << resultat->size() << std::endl;
    int compteur = 0;
    for(auto i = resultat->begin(); i != resultat->end(); i++){
        std::cout << "CFC numero " << compteur << std::endl;
        compteur++;
        for(auto j = i->begin(); j!= i->end(); *j++){
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
}


/**
 * Graphe page 101
 */
void test_Gabow_liste(){
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
    Gabow * gabow = new Gabow(graphe->nb_noeuds);
    std::vector<std::vector<int>> * resultat = gabow->gabow(graphe);
    std::cout << "nombre de CFC : " << resultat->size() << std::endl;
    int compteur = 0;
    for(auto i = resultat->begin(); i != resultat->end(); i++){
        std::cout << "CFC numero " << compteur << std::endl;
        compteur++;
        for(auto j = i->begin(); j!= i->end(); *j++){
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
}

void test_gabow(){
    std::clock_t start;
    double duration;
    for(int i = 100; i < 10000; i++){
        Graphe * graphe = GraphGenerator::genererGraphe(i);
        start = std::clock();
        Gabow * gabow = new Gabow(graphe->nb_noeuds);
        gabow->gabow(graphe);
        duration = std::clock() - start;
        std::cout << i << " " << duration <<std::endl;
    }
}

int main() {
    test_Kosaraju_liste();
    //test_DFS_liste();
    return 0;
}