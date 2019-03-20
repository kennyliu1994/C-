#include <iostream> // cout
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>   /* printf, NULL */
#include <stdlib.h>  /* srand, rand, exit */
#include <time.h>    /* time */
#include <math.h>    /* sqrt, pow */
#include <algorithm> // min, sort
#include <iomanip>   //setw
#include "lib.h"
using namespace std;

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
convert::convert(double input, vector<double> &output)
{
    vector<double> exponent;
    vector<double> mantissa;
    if (input >= 0)
    {
        output.push_back(1);
    }
};