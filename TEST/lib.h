#ifndef __LIB_H__
#define ____LIB_H__
using namespace std;

class convert
{
public:
  convert(string, int &);
  convert(string, double &);
  convert(vector<double>, double &, int); //2's complement vector to decimal
  convert(double, vector<double> &);      //decimal to binary vector

private:
};
#endif //__LIB_H__