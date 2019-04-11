#include "iostream"
using namespace std;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
    int x = 2;
    int y = 3;
    cout << MIN(x++, y++) << endl;
    cout << MIN(++x, ++y) << endl;
    return 0;
}
