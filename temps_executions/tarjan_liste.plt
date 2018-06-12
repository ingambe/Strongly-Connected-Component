set terminal png size 1024,768 enhanced font "Helvetica,20"
set output 'liste_tarjan.png'
set title 'Tarjan avec Graph Listes'
set xlabel 'Nombre de liens'
set ylabel 'Temps en nanosecondes'

set autoscale x

plot "liste_tarjan.txt" using 1:2 title 'tarjan' with lines
