#ifndef __LIB_H__
#define __LIB_H__

#include <vector>
#include <string>
using namespace std;

class rand_Kenny
{
public:
  int range_int(const int, const int);               //[low,upper] or low <= rand <= upper
  double range_double_1(const double, const double); //[low,upper)
  double range_double_2(const double, const double); //[low,upper]

private:
};
class convert
{
public:
  convert(string, int &);
  convert(string, double &);
  convert(vector<double>, double &, int); //2's complement vector to decimal

private:
};
class SSE
{
public:
  double distance(vector<double>, vector<double>);

private:
};

#endif //__LIB_H__