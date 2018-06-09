#include <iostream>
#include <stack>
#include <ctime>
#include "Graphes/Graphe_Liste.h"
#include "CFC/Kosaraju.h"
#include "CFC/Tarjan.h"
#include "CFC/Gabow.h"
#include "GraphGenerator.h"
#include "Graphes/Graphe_Adjacence.h"

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
    std::stack<int> dfs = graphe.dfs(0, new bool[12]{0});
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
    std::stack<int> dfs = graphe->dfs(0, new bool[8]{0});
    std::cout << "La taille doit etre de 8 : " << dfs.size() << std::endl;
    afficher_pile(dfs);
    free(graphe);
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
    CFC_Implementation * kosaraju = new Kosaraju();
    std::vector<std::set<int>> * resultat = kosaraju->CFC(graphe);
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
    free(graphe);
}
void test_Kosaraju_adjacence(){
    Graphe_Adjacence * graphe = new Graphe_Adjacence(8);
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
    CFC_Implementation * kosaraju = new Kosaraju();
    std::vector<std::set<int>> * resultat = kosaraju->CFC(graphe);
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
    free(kosaraju);
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
    CFC_Implementation * tarjan = new Tarjan();
    std::vector<std::set<int>> * resultat = tarjan->CFC(graphe);
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
    CFC_Implementation * gabow = new Gabow(graphe->nb_noeuds);
    std::vector<std::set<int>> * resultat = gabow->CFC(graphe);
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
 * FONCTIONS TEST TEMPS
 */

// LISTES

void test_liste_gabow(){
    std::clock_t start;
    double duration;
    for(int i = 100; i < 10000; i = i + 10){
        for(int j = 0; j <5; j++) {
            Graphe *graphe = GraphGenerator::genererGrapheListe(i);
            start = std::clock();
            CFC_Implementation *gabow = new Gabow(graphe->nb_noeuds);
            gabow->CFC(graphe);
            duration = std::clock() - start;
            std::cout << i << " " << duration / (double) CLOCKS_PER_SEC << std::endl;
            free(graphe);
            free(gabow);
        }
    }
}


void test_liste_kosaraju(){
    std::clock_t start;
    double duration;
    for(int i = 100; i < 10000; i = i + 10){
        for(int j = 0; j <5; j++) {
            Graphe *graphe = GraphGenerator::genererGrapheListe(i);
            start = std::clock();
            CFC_Implementation *kosaraju = new Kosaraju();
            kosaraju->CFC(graphe);
            duration = std::clock() - start;
            std::cout << i << " " << duration / (double) CLOCKS_PER_SEC << std::endl;
            free(graphe);
        }
    }
}


void test_liste_tarjan(){
    std::clock_t start;
    double duration;
    for(int i = 100; i < 10000; i = i + 10){
        for(int j = 0; j <5; j++) {
            Graphe *graphe = GraphGenerator::genererGrapheListe(i);
            start = std::clock();
            CFC_Implementation *tarjan = new Tarjan();
            tarjan->CFC(graphe);
            duration = std::clock() - start;
            std::cout << i << " " << duration / (double) CLOCKS_PER_SEC << std::endl;
            free(graphe);
            free(tarjan);
        }
    }
}

// ADJACENCE

void test_adjacence_gabow(){
    std::clock_t start;
    double duration;
    for(int i = 100; i < 10000; i = i + 10){
        for(int j = 0; j <5; j++) {
            Graphe *graphe = GraphGenerator::genererGrapheAdjacence(i);
            start = std::clock();
            CFC_Implementation *gabow = new Gabow(graphe->nb_noeuds);
            gabow->CFC(graphe);
            duration = std::clock() - start;
            std::cout << i << " " << duration / (double) CLOCKS_PER_SEC << std::endl;
            free(graphe);
            free(gabow);
        }
    }
}


void test_adjacence_kosaraju(){
    std::clock_t start;
    double duration;
    for(int i = 100; i < 10000; i = i + 10){
        for(int j = 0; j <5; j++) {
            Graphe *graphe = GraphGenerator::genererGrapheAdjacence(i);
            start = std::clock();
            CFC_Implementation * kosaraju = new Kosaraju();
            kosaraju->CFC(graphe);
            duration = std::clock() - start;
            std::cout << i << " " << duration / (double) CLOCKS_PER_SEC << std::endl;
            free(graphe);
            free(kosaraju);
        }
    }
}


void test_adjacence_tarjan(){
    std::clock_t start;
    double duration;
    for(int i = 100; i < 10000; i = i + 10){
        for(int j = 0; j <5; j++) {
            Graphe *graphe = GraphGenerator::genererGrapheAdjacence(i);
            start = std::clock();
            CFC_Implementation *tarjan = new Tarjan();
            tarjan->CFC(graphe);
            duration = std::clock() - start;
            std::cout << i << " " << duration / (double) CLOCKS_PER_SEC << std::endl;
            free(graphe);
            free(tarjan);
        }
    }
}

void test_Kosaraju_Liste2(){
    Graphe_Liste * graphe = new Graphe_Liste(8);
    graphe->ajouterLien(0,1);
    graphe->ajouterLien(4,0);
    graphe->ajouterLien(0,5);
    graphe->ajouterLien(1,5);
    graphe->ajouterLien(5,4);
    graphe->ajouterLien(1,2);
    graphe->ajouterLien(5,6);
    graphe->ajouterLien(6,2);
    graphe->ajouterLien(2,6);
    graphe->ajouterLien(2,3);
    graphe->ajouterLien(7,6);
    CFC_Implementation * kosaraju = new Kosaraju();
    std::vector<std::set<int>> * resultat = kosaraju->CFC(graphe);
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
    free(graphe);
}

int main(int argc, char *argv[]) {
    if(argc > 1){
        if(std::string(argv[1]) == "liste"){
            if(std::string(argv[2]) == "gabow"){
                test_liste_gabow();
            } else if(std::string(argv[2]) == "kosaraju"){
                test_liste_kosaraju();
            } else {
                test_liste_tarjan();
            }
        } else {
            if(std::string(argv[2]) == "gabow"){
                test_adjacence_gabow();
            } else if(std::string(argv[2]) == "kosaraju"){
                test_adjacence_kosaraju();
            } else {
                test_adjacence_tarjan();
            }
        }
    } else {
        printf("----------------Programme de test d'algorithme de CFC pour le cour de Mr Regin----------------\n");
        printf("usage : ./executable type algorithme\n");
        printf("exemple : ./graphes liste kosaraju\n\n");
        printf("Liste des arguments :\n\n");
        printf("\tType Representation :\n");
        printf("\t-liste : graphe de liste d\'ajacence\n");
        printf("\t-adjacence : graphe de matrice d\'ajacence\n");
        printf("\n");
        printf("\tAlgorithme:\n");
        printf("\t-gabow : algorithme gabow\n");
        printf("\t-kosaraju : algorithme kosaraju\n");
        printf("\t-tarjan : algorithme tarjan\n");
        printf("\n");
    }
    return 0;
}