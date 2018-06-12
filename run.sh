#!/usr/bin/env bash
cd cmake-build-release

echo "debut compilation"

make

echo "compilation reussie"

echo "debut generation temps execution"

#Liste
echo "liste"

echo "gabow"
./graphes liste gabow > ../temps_executions/liste_gabow.txt

echo "kosaraju"
./graphes liste kosaraju > ../temps_executions/liste_kosaraju.txt

echo "tarjan"
./graphes liste tarjan > ../temps_executions/liste_tarjan.txt

#Matrice adjacence
echo "matrice"

echo "gabow"
./graphes matrice gabow > ../temps_executions/matrice_gabow.txt

echo "kosaraju"
./graphes matrice kosaraju > ../temps_executions/matrice_kosaraju.txt

echo "tarjan"
./graphes matrice tarjan > ../temps_executions/matrice_tarjan.txt

echo "fin"

cd ..

echo "debut dessin courbes"

cd temps_executions

gnuplot gabow_liste.plt
gnuplot kosaraju_liste.plt
gnuplot tarjan_liste.plt

gnuplot gabow_matrice.plt
gnuplot kosaraju_matrice.plt
gnuplot tarjan_matrice.plt

cd ..
