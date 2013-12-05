set terminal png
set size 1,1
set terminal png size 1600,900
set output 'Algoritm.png'
set title 'Algoritm'
set xlabel 'time, s'
set ylabel 'Bitrate'
set grid


plot "graph/example.txt" using 1:2 title 'Column' with linespoints ,\
     "graph/example.txt" using 1:3 title 'Column' with linespoints
