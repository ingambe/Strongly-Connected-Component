set terminal png size 1024,768 enhanced font "Helvetica,20"
set output 'liste_gabow.png'
set title 'Gabow avec Graph Listes'
set xlabel 'Nombre de liens'
set ylabel 'Temps en nanosecondes'

plot "liste_gabow.txt" using 1:2 title 'gabow' with lines
