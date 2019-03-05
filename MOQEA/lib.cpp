#include <iostream> // cout
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>   /* printf, NULL */
#include <stdlib.h>  /* srand, rand, exit */
#include <time.h>    /* time */
#include <math.h>    /* sqrt, pow */
#include <algorithm> // min
#include "lib.h"
using namespace std;

int rand_Kenny::range(const int lowerBound, const int upperBound)
{
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}
convert::convert(string intput, int &output)
{
    stringstream ss(intput);
    ss >> output;
}
convert::convert(string intput, double &output)
{
    stringstream ss(intput);
    ss >> output;
}
double SSE::distance(vector<double> a, vector<double> b)
{
    double sum = 0;
    for (unsigned int i = 0; i < a.size(); i++)
        sum += pow(a[i] - b[i], 2);
    //return sqrt(sum);//Euclidean distance
    return sum; //Error Sum of Squares
}