#include "Kenny.h"
#include <stdlib.h> /* srand, rand */
#include <sstream>  //stringstream

int Kenny_rand::int11(const int lower, const int upper)
{
    return rand() % (upper - lower + 1) + lower;
}
double Kenny_rand::double10(double lower, double upper)
{
    return (double)(upper - lower) * rand() / (RAND_MAX + 1.0) + lower;
}
double Kenny_rand::double11(double lower, double upper)
{
    return (double)(upper - lower) * rand() / (RAND_MAX) + lower;
}

string Kenny_convert::int2str(const int input)
{
    stringstream ss;
    ss << input;
    return ss.str();
}

int Kenny_convert::str2int(const string input)
{
    int output;
    istringstream iss(input);
    iss >> output;
    return output;
}

const char *Kenny_convert::int2char(const int input)
{
    return int2str(input).c_str();
}

int Kenny_convert::char2int(const char *input)
{
    return atoi(input);
}

const char *Kenny_convert::str2char(const string input)
{
    return input.c_str();
}
string Kenny_convert::char2str(const char *input)
{
    string s(input);
    return s;
}

void split(const string s, vector<string> &vs, const char delim)
{
    vs.clear();
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, delim))
    {
        vs.emplace_back(move(temp));
    }
    ss.str("");
    ss.clear();
}