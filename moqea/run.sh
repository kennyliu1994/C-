#!bin/bash

make clean all

./moqea sch1 <./gnuplot/sch1.in
#gnuplot -c gnuplot/test.gp sch1 gnuplot/sch1.png final_pop.out
