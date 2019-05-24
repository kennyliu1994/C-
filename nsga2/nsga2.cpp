#include "iostream"

#include "global.h"

int main(int argc, char **argv)
{
    fstream gp;
    gp.open("plot.gp", ios::out); //write
    if (gp.fail())
    {
        cout << "Can't open file!" << endl;
        exit(1);
    }
    display(gp, 1);
    return 0;
}