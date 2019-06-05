#!bin/bash

make clean all

mkdir output

./moqea sch1 <./gnuplot/sch1.in
mkdir output/sch1
cp final_pop.out output/sch1/
gnuplot -c gnuplot/test.gp sch1 gnuplot/sch1.png final_pop.out