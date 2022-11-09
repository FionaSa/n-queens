set terminal png size 500,500
set output 'plot.png'
set title 'Evolution reines'
set xlabel 'Reines'

set ylabel 'Cycles'

set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 2 linewidth 2 \
    pointtype 7 pointsize 1.5


plot 'plot.dat' using 1:2 title "Données" with linespoints linestyle 1
