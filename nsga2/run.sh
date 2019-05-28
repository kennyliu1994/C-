#!bin/bash

make clean all

./nsga2 sch1 <./gnuplot/sch1.in
gnuplot -c gnuplot/test.gp sch1 gnuplot/sch1.png final_pop.out

./nsga2 sch2 <./gnuplot/sch2.in
gnuplot -c gnuplot/test.gp sch2 gnuplot/sch2.png final_pop.out

./nsga2 fon <./gnuplot/fon.in
gnuplot -c gnuplot/test.gp fon gnuplot/fon.png final_pop.out

./nsga2 kur <./gnuplot/kur.in
gnuplot -c gnuplot/test.gp kur gnuplot/kur.png final_pop.out

./nsga2 pol <./gnuplot/pol.in
gnuplot -c gnuplot/test.gp pol gnuplot/pol.png final_pop.out

./nsga2 vnt <./gnuplot/vnt.in
gnuplot -c gnuplot/test.gp vnt gnuplot/vnt.png final_pop.out

./nsga2 zdt1 <./gnuplot/zdt1.in
gnuplot -c gnuplot/test.gp zdt1 gnuplot/zdt1.png final_pop.out

./nsga2 zdt2 <./gnuplot/zdt2.in
gnuplot -c gnuplot/test.gp zdt2 gnuplot/zdt2.png final_pop.out

./nsga2 zdt3 <./gnuplot/zdt3.in
gnuplot -c gnuplot/test.gp zdt3 gnuplot/zdt3.png final_pop.out

./nsga2 zdt4 <./gnuplot/zdt4.in
gnuplot -c gnuplot/test.gp zdt4 gnuplot/zdt4.png final_pop.out

./nsga2 zdt6 <./gnuplot/zdt6.in
gnuplot -c gnuplot/test.gp zdt6 gnuplot/zdt6.png final_pop.out