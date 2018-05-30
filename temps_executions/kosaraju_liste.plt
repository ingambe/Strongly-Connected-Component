set terminal png size 1024,768 enhanced font "Helvetica,20"
set output 'liste_kosaraju.png'
set title 'Kosaraju avec Graph Listes'
set xlabel 'Nombre de liens'
set ylabel 'Temps en secondes'

plot "liste_kosaraju.txt" using 1:2 title 'kosaraju' with lines
