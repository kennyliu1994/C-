#ifndef __KMEANS_H__
#define ____KMEANS_H__
using namespace std;

class txtToVector
{
public:
  txtToVector(const char *, vector<string>[], const int, const int);

private:
};
class individual
{
public:
  int inWhichCluster;
  double disToCluster;

private:
};
#endif //__KMEANS_H__