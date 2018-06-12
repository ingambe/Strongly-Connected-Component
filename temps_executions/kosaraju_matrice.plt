set terminal png size 1024,768 enhanced font "Helvetica,20"
set output 'matrice_kosaraju.png'
set title 'Kosaraju avec Matrice Adjacence'
set xlabel 'Nombre de liens'
set ylabel 'Temps en millisecondes'

plot "matrice_kosaraju.txt" using 1:2 title 'kosaraju' with lines
