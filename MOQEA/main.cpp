#include "lib.h"
#include <math.h>   /* sqrt, pow */
#include <iostream> // cout
#include <stdlib.h> /* srand, rand, exit */

const unsigned int n = 3;         //number of individual
const unsigned int s = 1;         //sign bit
const unsigned int pl = 2;        //point left
const unsigned int pr = 3;        //point right
unsigned int m = s + pl + pr;     //Q-bit individual 長度
unsigned int t;                   //目前第幾代
const unsigned int iteration = 1; //總迭代數

class individual //Q,P,Pc
{
  public:
    vector<double> alpha;
    vector<double> beta;
    vector<double> content;
    double decimal;
    double fitness1;
    double fitness2;
    unsigned int index;
    vector<double> Sp;
    unsigned int np;

  private:
};
class MOQEA
{
  public:
    void initialize(class individual indi[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            indi[i].alpha.resize(m, 1 / sqrt(2)); //Q(0)每個為根號2分之1
            indi[i].beta.resize(m, 1 / sqrt(2));
            indi[i].content.resize(m);
            indi[i].decimal = 0.0;
            indi[i].fitness1 = 0.0;
            indi[i].fitness2 = 0.0;
            indi[i].np = 0;
            indi[i].index = 0;
        }
    };
    void make(class individual inid[n], class individual inid_child[n])
    {
        rand_Kenny rd;
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                if (rd.range_double_1(0, 1.0) < pow(inid[i].beta[j], 2))
                    inid_child[i].content[j] = 1;
                else
                    inid_child[i].content[j] = 0;
            }
        }
    }
    void evaluate(class individual inid[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            convert binvec2dec(inid[i].content, inid[i].decimal, pl);
            inid[i].fitness1 = obj1(inid[i].decimal);
            inid[i].fitness2 = obj2(inid[i].decimal);
        }
    }
    void show(class individual indi[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            cout << "Q" << i << "(" << t << ").alpha = [";
            for (unsigned int j = 0; j < m - 1; j++)
            {
                cout << indi[i].alpha[j] << " , ";
            }
            cout << indi[i].alpha[m - 1] << "]" << endl;
            cout << "Q" << i << "(" << t << ").beta = [";
            for (unsigned int j = 0; j < m - 1; j++)
            {
                cout << indi[i].beta[j] << " , ";
            }
            cout << indi[i].beta[m - 1] << "]" << endl;
            cout << "P" << i << "(" << t << ") = ";
            for (unsigned int j = 0; j < m; j++)
                cout << indi[i].content[j];
            cout << " , decimal = " << indi[i].decimal;
            cout << " , fitness1 = " << indi[i].fitness1;
            cout << " , fitness2 = " << indi[i].fitness2 << endl;
        }
    };
    void fastNondominatedSort(individual inid[n], individual inid_child[n], vector<double> F[n])
    {
        vector<individual> R[2*n];
        for (unsigned int i = 0; i < n; i++)
        {
            inid[i].index += i + 1;
        }
        for (unsigned int i = 0; i < n; i++)
        {
            inid_child[i].index += i + 1 + n;
        }
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < n; j++)
            {
                //cout << "show fitness : " << endl;
                //cout << inid[i].fitness1 << " , " << inid[i].fitness2 << " , " << inid_child[j].fitness1 << " , " << inid_child[j].fitness2 << endl;
                //cout << "show dominate status : " << endl;
                //cout << dominate(inid[i].fitness1, inid[i].fitness2, inid_child[j].fitness1, inid_child[j].fitness2) << endl;
                if (dominate(inid[i].fitness1, inid[i].fitness2, inid_child[j].fitness1, inid_child[j].fitness2) == 0)
                {
                    inid[i].Sp.push_back(inid_child[j].index);
                    inid_child[j].np++;
                }
                else if (dominate(inid[i].fitness1, inid[i].fitness2, inid_child[j].fitness1, inid_child[j].fitness2) == 1)
                {
                    inid_child[j].Sp.push_back(inid[i].index);
                    inid[i].np++;
                }
            }
        }
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = i + 1; j < n; j++)
            {
                if (dominate(inid[i].fitness1, inid[i].fitness2, inid[j].fitness1, inid[j].fitness2) == 0)
                {
                    inid[i].Sp.push_back(inid[j].index);
                    inid[j].np++;
                }
                else if (dominate(inid[i].fitness1, inid[i].fitness2, inid[j].fitness1, inid[j].fitness2) == 1)
                {
                    inid[j].Sp.push_back(inid[i].index);
                    inid[i].np++;
                }
                if (dominate(inid_child[i].fitness1, inid_child[i].fitness2, inid_child[j].fitness1, inid_child[j].fitness2) == 0)
                {
                    inid_child[i].Sp.push_back(inid_child[j].index);
                    inid_child[j].np++;
                }
                else if (dominate(inid_child[i].fitness1, inid_child[i].fitness2, inid_child[j].fitness1, inid_child[j].fitness2) == 1)
                {
                    inid_child[j].Sp.push_back(inid_child[i].index);
                    inid_child[i].np++;
                }
            }
        }
        for (unsigned int i = 0; i < n; i++)
        {
            if (inid[i].np == 0)
                F[0].push_back(inid[i].index);
            if (inid_child[i].np == 0)
                F[0].push_back(inid_child[i].index);
        }
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            if (F[i].size() != 0)
            {
                for (unsigned int j = 0; j < F[i].size(); j++)
                {
                }
            }
        }
    }
    void show_domination_info(individual inid[n], individual inid_child[n], vector<double> F[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            cout << "inid" << i << "(" << t - 1 << ")";
            cout << " , Sp = [";
            for (unsigned int j = 0; j < inid[i].Sp.size(); j++)
                cout << inid[i].Sp[j] << " ";
            cout << "]";
            cout << " , np = " << inid[i].np;
            cout << " , index = " << inid[i].index << endl;
        }
        for (unsigned int i = 0; i < n; i++)
        {
            cout << "inid" << i << "(" << t << ")";
            cout << " , Sp = [";
            for (unsigned int j = 0; j < inid_child[i].Sp.size(); j++)
                cout << inid_child[i].Sp[j] << " ";
            cout << "]";
            cout << " , np = " << inid_child[i].np;
            cout << " , index = " << inid_child[i].index << endl;
        }
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            cout << "F" << i + 1 << " = [";
            for (unsigned int j = 0; j < F[i].size(); j++)
                cout << F[i][j] << " ";
            cout << "]" << endl;
        }
    }

  private:
    double obj1(double sum)
    {
        return pow(sum, 2);
    }
    double obj2(double sum)
    {
        return pow(sum - 2, 2);
    }
    int dominate(double x1, double x2, double y1, double y2)
    {
        if (x1 < y1)
        {
            if (x2 > y2)
                return 2; //none
            else
                return 0; //dominate
        }
        else if (x1 > y1)
        {
            if (x2 < y2)
                return 2;
            else
                return 1; //is dominated
        }
        else
        {
            if (x2 < y2)
                return 0;
            else if (x2 == y2)
                return 2;
            else
                return 1;
        }
    }
};
/*
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
void update(vector<double> inid, vector<double> B, double obj, double Best, vector<vector<double>> &Q)
{
    double theta;
    for (unsigned int i = 0; i < m; i++)
    {
        theta = lookup(inid[i], B[i], obj, Best);
        if (Q[0][i] * Q[1][i] > 0)
            theta = -theta;
        Q[0][i] = cos(theta) * Q[0][i] - sin(theta) * Q[1][i];
        Q[1][i] = sin(theta) * Q[0][i] + cos(theta) * Q[1][i];
    }
}*/
int main()
{
    srand((unsigned)time(NULL));
    /*fstream file;
    file.open("output.txt", ios::out | ios::app); //open
    if (file.fail())
    {
        cout << "Can't open file!\n";
        exit(1);
    }*/
    MOQEA test;
    t = 0;
    individual indi[n]; //n q-bit individuals
    test.initialize(indi);
    test.make(indi, indi);
    test.evaluate(indi); //test.show(indi);
    individual indi_child[n];
    test.initialize(indi_child);
    do
    {
        t++;
        test.make(indi, indi_child);
        test.evaluate(indi_child); //test.show(indi_child);
        vector<double> F[n];
        test.fastNondominatedSort(indi, indi_child, F);
        test.show_domination_info(indi, indi_child, F);
        //fast
        //crowding
        //child to parent
        /*
        fastNondominatedSort(inid, inid_child, F[0]);
        show_domination_info(inid, inid_child, F[0]);*/
    } while (t < iteration);
    //file.close();
    return 0;
}