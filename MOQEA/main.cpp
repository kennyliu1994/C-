#include "lib.h"
#include <iostream> // cout
#include <stdlib.h> /* srand, rand, exit */
#include <fstream>
#include <algorithm> // min sort
#include <limits>    // numeric_limits<double>::max()

const unsigned int dim = 30; //dimension
const unsigned int n = 10;   //number of individual
const unsigned int s = 1;    //sign bit
//const unsigned int pl = 9;  //point left SCH
//const unsigned int pl = 3;          //point left KUR
const unsigned int pl = 0;          //point left ZDT2
const unsigned int pr = 10;         //point right
unsigned int m = s + pl + pr;       //Q-bit individual 長度
unsigned int t;                     //目前第幾代
const unsigned int iteration = 100; //總迭代數

class individual //Q,P,Pc
{
  public:
    vector<double> alpha;
    vector<double> beta;
    vector<double> content[dim];
    vector<double> Sp;
    vector<double> decimal;
    double fitness1;
    double fitness2;
    double d;
    unsigned int np;
    unsigned int index;

  private:
};
class testFunction
{
  public:
    void SCH(class individual indi[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < dim; j++)
            {
                indi[i].fitness1 = pow(indi[i].decimal[j], 2);
                indi[i].fitness2 = pow(indi[i].decimal[j] - 2, 2);
            }
        }
    }
    /*void KUR(class individual indi[n])
    {
        double res1;
        double res2;
        res1 = -0.2 * sqrt((indi[0].decimal * indi[0].decimal) + (indi[1].decimal * indi[1].decimal));
        res2 = -0.2 * sqrt((indi[1].decimal * indi[1].decimal) + (indi[2].decimal * indi[2].decimal));        
        for (unsigned int i = 0; i < 3; i++)
        {
            indi[i].fitness1 = -10.0 * (exp(res1) + exp(res2));
            indi[i].fitness2 += pow(fabs(indi[i].decimal), 0.8) + 5.0 * sin(pow(indi[i].decimal, 3.0));
        }
    }*/
    void ZDT1(class individual indi[n])
    {
        double f1, f2, g, h;
        for (unsigned int i = 0; i < n; i++)
        {
            f1 = indi[i].decimal[0];
            g = 0.0;
            for (unsigned int j = 1; j < dim; j++)
            {
                g += indi[i].decimal[j];
            }
            g = 9.0 * g / 29.0;
            g += 1.0;
            h = 1.0 - sqrt(f1 / g);
            f2 = g * h;
            indi[i].fitness1 = f1;
            indi[i].fitness2 = f2;
        }
    }
    void ZDT2(class individual indi[n])
    {
        double f1, f2, g, h;
        for (unsigned int i = 0; i < n; i++)
        {
            f1 = indi[i].decimal[0];
            g = 0;
            for (unsigned int j = 1; j < dim; j++)
            {
                g += indi[i].decimal[j];
            }
            g = 9 * g / 29;
            g += 1;
            h = 1 - pow((f1 / g), 2);
            f2 = g * h;
            indi[i].fitness1 = f1;
            indi[i].fitness2 = f2;
        }
    }
    void ZDT3(class individual indi[n])
    {
        double f1, f2, g, h;
        for (unsigned int i = 0; i < n; i++)
        {
            f1 = indi[i].decimal[0];
            g = 0;
            for (unsigned int j = 1; j < dim; j++)
            {
                g += indi[i].decimal[j];
            }
            g = 9.0 * g / 29.0;
            g += 1.0;
            h = 1.0 - sqrt(f1 / g) - (f1 / g) * sin(10.0 * M_PI * f1);
            f2 = g * h;
            indi[i].fitness1 = f1;
            indi[i].fitness2 = f2;
        }
    }

  private:
};
class MOQEA
{
  public:
    void initialize(class individual indi[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            //indi[i].alpha.clear();
            indi[i].alpha.resize(m, 1 / sqrt(2)); //Q(0)每個為根號2分之1
            //indi[i].beta.clear();
            indi[i].beta.resize(m, 1 / sqrt(2));
            for (unsigned int j = 0; j < dim; j++)
            {
                indi[i].content[j].resize(m);
            }
            indi[i].decimal.clear();
            indi[i].decimal.resize(dim, 0);
            indi[i].Sp.clear();
            indi[i].fitness1 = 0.0;
            indi[i].fitness2 = 0.0;
            indi[i].d = 0.0;
            indi[i].np = 0;
            indi[i].index = 0;
        }
    };
    void make(class individual indi[n], class individual indi_child[n])
    {
        rand_Kenny rd;
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < dim; j++)
            {
                for (unsigned int k = 0; k < m; k++)
                {
                    if (rd.range_double_1(0, 1.0) < pow(indi[i].beta[k], 2))
                        indi_child[i].content[j][k] = 1;
                    else
                        indi_child[i].content[j][k] = 0;
                }
            }
        }
    }
    void evaluate(class individual indi[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < dim; j++)
            {
                convert binvec2dec(indi[i].content[j], indi[i].decimal[j], pl);
            }
        }
        testFunction test;
        test.ZDT3(indi);
    }
    void show(class individual indi[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            cout << "P" << i << "(" << t << ") = ";
            for (unsigned int j = 0; j < dim; j++)
            {
                for (unsigned int k = 0; k < m; k++)
                {
                    cout << indi[i].content[j][k];
                }
                cout << " , ";
            }
            cout << endl
                 << "decimal = ";
            for (unsigned int j = 0; j < dim; j++)
            {
                cout << indi[i].decimal[j] << " , ";
            }
            cout << endl
                 << "fitness1 = " << indi[i].fitness1;
            cout << " , fitness2 = " << indi[i].fitness2 << endl;
        }
    };
    void crowdingDAss(vector<int> &F, vector<individual> R)
    {
        sortF.clear();
        for (unsigned int i = 0; i < F.size(); i++)
        {
            sortF.push_back(R[F[i] - 1]);
        }
        //依照fit1排序一次
        sort(sortF.begin(), sortF.end(), cmpByFit1); //對整個class的某項參數作為依據排序
        //清空d
        for (unsigned int i = 0; i < sortF.size(); i++)
        {
            sortF[i].d = 0;
        }
        //設頭尾的d為無限大
        sortF.front().d = numeric_limits<double>::max();
        sortF.back().d = numeric_limits<double>::max();
        //show_d(sortF);
        //算中間的d
        for (unsigned int i = 1; i < sortF.size() - 1; i++)
        {
            sortF[i].d += (sortF[i + 1].fitness1 - sortF[i - 1].fitness1) / (sortF.back().fitness1 - sortF.front().fitness1);
        }
        //show_d(sortF);
        //依照fit2排序一次
        sort(sortF.begin(), sortF.end(), cmpByFit2); //對整個class的某項參數作為依據排序
        //算中間的d
        for (unsigned int i = 1; i < sortF.size() - 1; i++)
        {
            sortF[i].d += (sortF[i + 1].fitness2 - sortF[i - 1].fitness2) / (sortF.back().fitness2 - sortF.front().fitness2);
        }
        //show_d(sortF);
        //依照d排序
        sort(sortF.begin(), sortF.end(), cmpByd);
        //改變F裡的順序
        F.clear();
        for (unsigned int i = 0; i < sortF.size(); i++)
        {
            F.push_back(sortF[i].index);
        }
    }
    void fastSortAndCrowdingD(individual indi[n], individual indi_child[n], vector<int> F[2 * n])
    {
        R.clear();
        for (unsigned int i = 0; i < n; i++)
        {
            R.push_back(indi[i]);
        }
        for (unsigned int i = 0; i < n; i++)
        {
            R.push_back(indi_child[i]);
        }
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            R[i].index = i + 1;
        }
        for (unsigned int i = 0; i < 2 * n - 1; i++)
        {
            for (unsigned int j = i + 1; j < 2 * n; j++)
            {
                //cout << "show fitness : " << endl;
                //cout << R[i].fitness1 << " , " << R[i].fitness2 << " , " << R[j].fitness1 << " , " << R[j].fitness2 << endl;
                //cout << "show dominate status : " << endl;
                //cout << dominate(R[i].fitness1, R[i].fitness2, R[j].fitness1, R[j].fitness2) << endl;
                if (dominate(R[i].fitness1, R[i].fitness2, R[j].fitness1, R[j].fitness2) == 0)
                {
                    R[i].Sp.push_back(j + 1);
                    R[j].np++;
                }
                else if (dominate(R[i].fitness1, R[i].fitness2, R[j].fitness1, R[j].fitness2) == 1)
                {
                    R[j].Sp.push_back(i + 1);
                    R[i].np++;
                }
            }
        }
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            if (R[i].np == 0)
                F[0].push_back(i + 1);
        }
        //show_domination_info(F);
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            if (F[i].size() != 0)
            {
                for (unsigned int j = 0; j < F[i].size(); j++)
                {
                    for (unsigned int k = 0; k < R[F[i][j] - 1].Sp.size(); k++)
                    {
                        R[R[F[i][j] - 1].Sp[k] - 1].np--;
                        if (R[R[F[i][j] - 1].Sp[k] - 1].np == 0)
                            F[i + 1].push_back(R[F[i][j] - 1].Sp[k]);
                    }
                }
            }
        }
        //show_domination_info(F);
        unsigned int needed_n = n; //需要 n 個傳回 child
        unsigned int th = 0;       //目前存到第幾個 child
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            if (F[i].size() > 2)
            {
                crowdingDAss(F[i], R);
            }
        }
        //show_domination_info(F);
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            if (F[i].size() == needed_n)
            {
                for (unsigned int j = 0; j < needed_n; j++)
                {
                    indi_child[th] = R[F[i][j] - 1];
                    th++;
                }
                //cout << "==" << endl;
                break;
            }
            else if (F[i].size() > needed_n)
            {
                for (unsigned int j = 0; j < needed_n; j++)
                {
                    indi_child[th] = R[F[i][j] - 1];
                    th++;
                }
                //cout << ">" << endl;
                break;
            }
            else
            {
                for (unsigned int j = 0; j < F[i].size(); j++)
                {
                    indi_child[th] = R[F[i][j] - 1];
                    th++;
                }
                needed_n -= F[i].size();
                //cout << "<" << endl;
            }
        }
    }
    void show(vector<int> F[2 * n])
    {
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            cout << "F" << i + 1 << " = [";
            for (unsigned int j = 0; j < F[i].size(); j++)
                cout << F[i][j] << " ";
            cout << "]" << endl;
        }
    };
    void update1(individual indi_child[n])
    {
        double theta;
        for (unsigned int i = 1; i < n; i++)
        {
            for (unsigned int j = 0; j < dim; j++)
            {
                for (unsigned int k = 0; k < m; k++)
                {
                    theta = lookup(indi_child[i].content[j][k], indi_child[0].content[j][k], indi_child[i].fitness1, indi_child[0].fitness1);
                    if (indi_child[i].alpha[m] * indi_child[i].beta[m] > 0)
                        theta = -theta;
                    indi_child[i].alpha[k] = cos(theta) * indi_child[i].alpha[k] - sin(theta) * indi_child[i].beta[k];
                    indi_child[i].beta[k] = sin(theta) * indi_child[i].alpha[k] + cos(theta) * indi_child[i].beta[k];
                }
            }
        }
    }
    void update2(individual indi_child[n])
    {
        double theta;
        for (unsigned int i = 1; i < n; i++)
        {
            for (unsigned int j = 0; j < dim; j++)
            {
                for (unsigned int k = 0; k < m; k++)
                {
                    theta = lookup(indi_child[i].content[j][k], indi_child[0].content[j][k], indi_child[i].fitness2, indi_child[0].fitness2);
                    if (indi_child[i].alpha[k] * indi_child[i].beta[k] > 0)
                        theta = -theta;
                    indi_child[i].alpha[k] = cos(theta) * indi_child[i].alpha[k] - sin(theta) * indi_child[i].beta[k];
                    indi_child[i].beta[k] = sin(theta) * indi_child[i].alpha[k] + cos(theta) * indi_child[i].beta[k];
                }
            }
        }
    }

  private:
    vector<individual> R;
    vector<individual> sortF;
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
    void show_domination_info(vector<int> F[2 * n])
    {
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            cout << "R" << i << "(" << t << ")";
            cout << " , Sp = [";
            for (unsigned int j = 0; j < R[i].Sp.size(); j++)
                cout << R[i].Sp[j] << " ";
            cout << "]";
            cout << " , np = " << R[i].np;
            cout << " , index = " << R[i].index << endl;
        }
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            cout << "F" << i + 1 << " = [";
            for (unsigned int j = 0; j < F[i].size(); j++)
                cout << F[i][j] << " ";
            cout << "]" << endl;
        }
    }
    static bool cmpByFit1(individual const &a, individual const &b)
    {
        return a.fitness1 < b.fitness1;
    };
    static bool cmpByFit2(individual const &a, individual const &b)
    {
        return a.fitness2 < b.fitness2;
    };
    static bool cmpByd(individual const &a, individual const &b)
    {
        return a.d > b.d;
    };
    void show_d(vector<individual> sortF)
    {
        cout << "sortF[i].d = [";
        for (unsigned int i = 0; i < sortF.size(); i++)
        {
            cout << sortF[i].d << " ";
        }
        cout << "]" << endl;
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
};
int main()
{
    srand((unsigned)time(NULL));
    fstream file;
    file.open("output.txt", ios::out | ios::app); //open
    if (file.fail())
    {
        cout << "Can't open file!\n";
        exit(1);
    }
    MOQEA test;
    t = 0;
    individual indi[n]; //n q-bit individuals
    test.initialize(indi);
    test.make(indi, indi);
    test.evaluate(indi);
    individual indi_child[n];
    vector<int> F[2 * n];
    while (t < iteration)
    {
        t++;
        test.initialize(indi_child);
        test.make(indi, indi_child);
        test.evaluate(indi_child);
        test.show(indi);
        test.show(indi_child);
        for (unsigned int i = 0; i < 2 * n; i++)
        {
            F[i].clear();
        }
        test.fastSortAndCrowdingD(indi, indi_child, F);
        //test.show(indi_child);
        //test.update1(indi_child);
        test.update2(indi_child);
        for (unsigned int i = 0; i < n; i++) //小孩變成父母
        {
            indi[i] = indi_child[i];
            file << indi_child[i].fitness1 << " " << indi_child[i].fitness2 << endl;
        }
        //test.show(indi_child);
    }
    file.close();
    return 0;
}