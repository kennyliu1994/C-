#include "iostream"
using namespace std;

int main()
{
    int a[10][20][30][40];
    cout << a[0] - a[6] << endl;
    cout << a[0][0] - a[6][0] << endl;
    return 0;
}