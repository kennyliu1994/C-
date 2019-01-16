#ifndef __KMEANS_H__
#define ____KMEANS_H__
using namespace std;

class txtToVector
{
public:
  txtToVector(const char *, vector<double>[], const int, const int);

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
class individual
{
public:
  int index;
  int inWhichCluster;
  double distanceToCluster;

private:
};
#endif //__KMEANS_H__