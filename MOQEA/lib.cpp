#include "lib.h"
#include <sstream>
#include <math.h>    /* sqrt, pow */
#include <stdlib.h>  /* srand, rand, exit */

int rand_Kenny::range_int(const int lowerBound, const int upperBound)
{
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}
double rand_Kenny::range_double_1(const double lowerBound, const double upperBound)
{
    return (double)(upperBound - lowerBound) * rand() / (RAND_MAX + 1.0) + lowerBound;
}
double rand_Kenny::range_double_2(const double lowerBound, const double upperBound)
{
    return (double)(upperBound - lowerBound) * rand() / (RAND_MAX) + lowerBound;
}
convert::convert(string input, int &output)
{
    stringstream ss(input);
    ss >> output;
}
convert::convert(string input, double &output)
{
    stringstream ss(input);
    ss >> output;
}
convert::convert(vector<double> input, double &output, int pointleft)
{
    if (input.at(0) == 1)
        output -= input.at(0) * pow(2, pointleft);
    for (unsigned int i = 1; i < input.size(); i++)
    {
        output += input.at(i) * pow(2, pointleft - 1);
        pointleft--;
    }
}
double SSE::distance(vector<double> a, vector<double> b)
{
    double sum = 0;
    for (unsigned int i = 0; i < a.size(); i++)
        sum += pow(a[i] - b[i], 2);
    //return sqrt(sum);//Euclidean distance
    return sum; //Error Sum of Squares
}