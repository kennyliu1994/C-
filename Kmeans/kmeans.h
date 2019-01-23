#ifndef __KMEANS_H__
#define ____KMEANS_H__
using namespace std;

class txtToVector
{
public:
  txtToVector(const char *, vector<double>[], const unsigned int, const unsigned int);

private:
};
class rand_Kenny
{
public:
  int getFromRange(const int, const int);

private:
};
class convert
{
public:
  convert(string, int &);
  convert(string, double &);

private:
};
class euclidean
{
public:
  double distance(vector<double>, vector<double>);

private:
};
#endif //__KMEANS_H__