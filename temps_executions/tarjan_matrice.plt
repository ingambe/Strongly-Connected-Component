set terminal png size 1024,768 enhanced font "Helvetica,20"
set output 'matrice_tarjan.png'
set title 'Tarjan avec Matrice Adjacence'
set xlabel 'Nombre de liens'
set ylabel 'Temps en nanosecondes'

plot "matrice_tarjan.txt" using 1:2 title 'tarjan' with lines
