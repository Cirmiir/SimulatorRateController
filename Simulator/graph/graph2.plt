set terminal png
set size 1,1
set terminal png size 3200,1800
set output 'Clients.png'
set title 'Algoritm'
set xlabel 'time, s'
set ylabel 'Bitrate'
set grid


plot "graph/example.txt" using 1:2 title 'Column' with linespoints ,\
     "graph/example.txt" using 1:3 title 'Sum' with linespoints ,\
     "graph/example.txt" using 1:4 title 'Max' with linespoints ,\
     "graph/example.txt" using 1:6 title 'Max' with linespoints ,\
     "graph/example.txt" using 1:8 title 'Max' with linespoints 
     
