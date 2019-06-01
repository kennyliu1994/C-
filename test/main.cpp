#include <iostream>
using namespace std;

class B
{
public:
    virtual B *f(int n) { cout << "B=" << n << endl; }
};

class D : public B
{
public:
    D *f(int n) { cout << "D=" << n << endl; }
};

int main()
{
    D d;
    B &b = d;
    b.f(10);
    return 0;
}