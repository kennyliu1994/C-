#ifndef __KENNY_H__
#define __KENNY_H__

#include <string> // string
#include <vector>
using namespace std;

class Kenny_rand
{
private:
public:
    int int11(const int, const int);             //[low,upper]
    double double10(double lower, double upper); //[low,upper)
    double double11(double lower, double upper); //[low,upper]
};

class Kenny_convert
{
private:
public:
    string int2str(const int);
    int str2int(const string);
    const char* int2char(const int);
    int char2int(const char *);
    const char* str2char(const string);
    string char2str(const char *);
};

void split(const string , vector<string> &, const char);

#endif