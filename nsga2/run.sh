#!bin/bash

make clean all

./nsga2 sch1 <./gnuplot/sch1.in
mkdir output/sch1
cp final_pop.out output/sch1/
gnuplot -c gnuplot/test.gp sch1 gnuplot/sch1.png final_pop.out

./nsga2 sch2 <./gnuplot/sch2.in
mkdir output/sch2
cp final_pop.out output/sch2/
gnuplot -c gnuplot/test.gp sch2 gnuplot/sch2.png final_pop.out

./nsga2 fon <./gnuplot/fon.in
mkdir output/fon
cp final_pop.out output/fon/
gnuplot -c gnuplot/test.gp fon gnuplot/fon.png final_pop.out

./nsga2 kur <./gnuplot/kur.in
mkdir output/kur
cp final_pop.out output/kur/
gnuplot -c gnuplot/test.gp kur gnuplot/kur.png final_pop.out

./nsga2 pol <./gnuplot/pol.in
mkdir output/pol
cp final_pop.out output/pol/
gnuplot -c gnuplot/test.gp pol gnuplot/pol.png final_pop.out

./nsga2 vnt <./gnuplot/vnt.in
mkdir output/vnt
cp final_pop.out output/vnt/
gnuplot -c gnuplot/test.gp vnt gnuplot/vnt.png final_pop.out

./nsga2 zdt1 <./gnuplot/zdt1.in
mkdir output/zdt1
cp final_pop.out output/zdt1/
gnuplot -c gnuplot/test.gp zdt1 gnuplot/zdt1.png final_pop.out

./nsga2 zdt2 <./gnuplot/zdt2.in
mkdir output/zdt2
cp final_pop.out output/zdt2/
gnuplot -c gnuplot/test.gp zdt2 gnuplot/zdt2.png final_pop.out

./nsga2 zdt3 <./gnuplot/zdt3.in
mkdir output/zdt3
cp final_pop.out output/zdt3/
gnuplot -c gnuplot/test.gp zdt3 gnuplot/zdt3.png final_pop.out

./nsga2 zdt4 <./gnuplot/zdt4.in
mkdir output/zdt4
cp final_pop.out output/zdt4/
gnuplot -c gnuplot/test.gp zdt4 gnuplot/zdt4.png final_pop.out

./nsga2 zdt6 <./gnuplot/zdt6.in
mkdir output/zdt6
cp final_pop.out output/zdt6/
gnuplot -c gnuplot/test.gp zdt6 gnuplot/zdt6.png final_pop.out