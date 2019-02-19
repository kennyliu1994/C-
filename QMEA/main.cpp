#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
#include <stdlib.h> /* srand, rand, exit*/
#include <fstream>  /* fstream */

using namespace std;
//unsigned int n = 3; //item數目
unsigned int m = 5; //Q-bit individual 長度

void toDecimal(double &sum, vector<double> P)
{
    sum = 0.0;
    int ten;
    ten = 0;
    for (unsigned int i = 0; i < m; i++)
    {
        sum = sum + P[i] * pow(2, ten);
        ten--;
    }
    //cout << "sum = " << sum << endl;
}

void make_P(vector<vector<double> > Q, vector<double> &P)
{
    double x;
    for (unsigned int i = 0; i < m; i++)
    {
        x = (double)rand() / (RAND_MAX + 1.0);
        //cout << x << endl;
        //cout << pow(Q[1][i], 2) << endl;
        if (x < pow(Q[1][i], 2))
            P[i] = 1;
        else
            P[i] = 0;
    }
}

void show_P(vector<double> P)
{
    cout << "P(t) = ";
    for (unsigned int i = 0; i < m; i++)
        cout << P[i];
    cout << endl;
}

void show_B(vector<double> B)
{
    cout << "B(t) = ";
    for (unsigned int i = 0; i < m; i++)
        cout << B[i];
    cout << endl;
}

void show_Q(vector<vector<double> > Q)
{
    for (unsigned int i = 0; i < Q.size(); i++)
    {
        cout << "Q[" << i << "] = [";
        for (unsigned int j = 0; j < m - 1; j++)
        {
            cout << Q[i][j] << " , ";
        }
        cout << Q[i][m - 1] << "]" << endl;
    }
}

double obj1(double sum)
{
    return pow(sum, 2);
}

double obj2(double sum)
{
    return pow(sum - 2, 2);
}

double lookup(double x, double b, double fx, double fb)
{
    double theta;
    if ((x == 0) && (b = 1) && (fx < fb))
    {
        theta = 0.01 * M_PI;
    }
    else if ((x == 1) && (b = 0) && (fx < fb))
    {
        theta = -0.01 * M_PI;
    }
    else
    {
        theta = 0;
    }
    return theta;
}
void update(vector<double> P, vector<double> B, double obj, double Best, vector<vector<double> > &Q)
{
    double theta;
    for (unsigned int i = 0; i < m; i++)
    {
        theta = lookup(P[i], B[i], obj, Best);
        if (Q[0][i] * Q[1][i] > 0)
            theta = -theta;
        Q[0][i] = cos(theta) * Q[0][i] - sin(theta) * Q[1][i];
        Q[1][i] = sin(theta) * Q[0][i] + cos(theta) * Q[1][i];
    }
}
int main()
{
    /////////////////////////////////////////initialize
    srand(time(NULL));
    double sum = 0.0;
    fstream file;
    file.open("output.txt", ios::out | ios::app); //開啟檔案
    if (file.fail())                              //檢查檔案是否成功開啟
    {
        cout << "Can't open file!\n";
        exit(1); //在不正常情形下，中斷程式的執行
    }
    /////////////////////////////////////////initialize Q(t)
    vector<vector<double> > Q(2); //Q(2xm)
    for (unsigned int i = 0; i < Q.size(); i++)
    {
        Q[i].resize(m);
    }
    for (unsigned int i = 0; i < Q.size(); i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {            
            Q[i][j] = 1 / sqrt(2);//初始化Q(0)每個為根號2分之1
        }
    }
    //show_Q(Q);
    /////////////////////////////////////////make P(t) by Q(t)
    vector<double> P(m);
    make_P(Q, P);
    //show_P(P);
    /////////////////////////////////////////evaluate P(t), output
    toDecimal(sum, P);
    file << obj1(sum) << " " << obj2(sum) << endl;
    /////////////////////////////////////////store B(t), B
    vector<double> B(m);
    for (unsigned int i = 0; i < m; i++)
    {
        B[i] = P[i];
    }
    //show_B(B);
    double Best;
    Best = obj1(sum);
    /////////////////////////////////////////update
    update(P, B, obj1(sum), Best, Q);
    //show_Q(Q);
    /////////////////////////////////////////for loop
    /*for (unsigned int i = 0; i < 100; i++)
    {
        make_P(Q, P);
        //show_P(P);
        toDecimal(sum, P);
        file << obj1(sum) << " " << obj2(sum) << endl;
        if (obj1(sum) > Best)
        {
            for (unsigned int i = 0; i < m; i++)
            {
                B[i] = P[i];
            }
            //show_B(B);
            Best = obj1(sum);
        }
        update(P, B, obj1(sum), Best, Q);
        //show_Q(Q);
    }*/
    /////////////////////////////////////////
    /////////////////////////////////////////for loop2
    for (unsigned int i = 0; i < 100; i++)
    {
        make_P(Q, P);
        //show_P(P);
        toDecimal(sum, P);
        file << obj1(sum) << " " << obj2(sum) << endl;
        if (obj2(sum) > Best)
        {
            for (unsigned int i = 0; i < m; i++)
            {
                B[i] = P[i];
            }
            //show_B(B);
            Best = obj2(sum);
        }
        update(P, B, obj2(sum), Best, Q);
        //show_Q(Q);
    }
    /////////////////////////////////////////
    file.close();
    //cout << theta << endl;
    return 0;
}