#include "lib.cpp"

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

  private:
};
/*class binary //P,Pc
{
  public:
    
    vector<double> Sp;
    unsigned int np;
    unsigned int index;

  private:
};*/
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
            /*P[i].Sp.resize(2 * n - 1);
            P[i].np = 0;
            P[i].index = 0;*/
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
    void sort(class individual inid[n], class individual inid_child[n])
    {
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
    class NSGA2
    {
      public:
        void fastNondominatedSort();
        void crowdingDistance();
        void show_domination_info();

      private:
        vector<double> F[2 * n];
    };
};
/*
int dominate(double x1, double x2, double y1, double y2)
{
    if (x1 < y1)
    {
        if (x2 > y2)
            return 2;
        else
            return 0;
    }
    else if (x1 > y1)
    {
        if (x2 < y2)
            return 2;
        else
            return 1;
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
void fastNondominatedSort(individual P[n], individual P_child[n], vector<double> &F)
{
    for (unsigned int i = 0; i < n; i++)
    {
        P[i].index += i + 1;
    }
    for (unsigned int i = 0; i < n; i++)
    {
        P_child[i].index += i + 1 + n;
    }
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            cout << P[i].fitness1 << " , " << P[i].fitness2 << " , " << P_child[j].fitness1 << " , " << P_child[j].fitness2 << endl;
            cout << dominate(P[i].fitness1, P[i].fitness2, P_child[j].fitness1, P_child[j].fitness2) << endl;
            cout << P_child[j].index << endl;
            if (dominate(P[i].fitness1, P[i].fitness2, P_child[j].fitness1, P_child[j].fitness2) == 0)
            {
                P[i].Sp.push_back(P_child[j].index);
                P_child[j].np++;
            }
            else if (dominate(P[i].fitness1, P[i].fitness2, P_child[j].fitness1, P_child[j].fitness2) == 1)
            {
                P_child[j].Sp.push_back(P[i].index);
                P[i].np++;
            }
        }
    }
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = i + 1; j < n; j++)
        {
            if (dominate(P[i].fitness1, P[i].fitness2, P[j].fitness1, P[j].fitness2) == 0)
            {
                P[i].Sp.push_back(P[j].index);
                P[j].np++;
            }
            else if (dominate(P[i].fitness1, P[i].fitness2, P[j].fitness1, P[j].fitness2) == 1)
            {
                P[j].Sp.push_back(P[i].index);
                P[i].np++;
            }
            if (dominate(P_child[i].fitness1, P_child[i].fitness2, P_child[j].fitness1, P_child[j].fitness2) == 0)
            {
                P_child[i].Sp.push_back(P_child[j].index);
                P_child[j].np++;
            }
            else if (dominate(P_child[i].fitness1, P_child[i].fitness2, P_child[j].fitness1, P_child[j].fitness2) == 1)
            {
                P_child[j].Sp.push_back(P_child[i].index);
                P_child[i].np++;
            }
        }
    }
    for (unsigned int i = 0; i < n; i++)
    {
        if (P[i].np == 0)
            F.push_back(P[i].index);
    }
    for (unsigned int i = 0; i < n; i++)
    {
        if (P_child[i].np == 0)
            F.push_back(P_child[i].index);
    }
}
void show_domination_info(individual P[n], individual P_child[n], vector<double> F)
{
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "P" << i << "(" << t - 1 << ")";
        cout << " , Sp = [";
        for (unsigned int j = 0; j < P[i].Sp.size(); j++)
            cout << P[i].Sp[j] << ",";
        cout << "]";
        cout << " , np = " << P[i].np;
        cout << " , index = " << P[i].index << endl;
    }
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "P" << i << "(" << t << ")";
        cout << " , Sp = [";
        for (unsigned int j = 0; j < P_child[i].Sp.size(); j++)
            cout << P_child[i].Sp[j] << ",";
        cout << "]";
        cout << " , np = " << P_child[i].np;
        cout << " , index = " << P_child[i].index << endl;
    }
    cout << "F = [";
    for (unsigned int i = 0; i < F.size(); i++)
        cout << F[i] << ",";
    cout << "]" << endl;
}*/
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
void update(vector<double> P, vector<double> B, double obj, double Best, vector<vector<double>> &Q)
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
}*/
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
    MOQEA SCH;
    individual indi[n];   //n q-bit individuals
    SCH.initialize(indi); //SCH.show(indi);
    SCH.make(indi, indi);
    SCH.evaluate(indi); SCH.show(indi);
    individual indi_child[n];
    SCH.initialize(indi_child);
    while (t < iteration)
    {
        t++;
        SCH.make(indi, indi_child);
        SCH.evaluate(indi_child); //SCH.show(indi_child);
        /*
        fastNondominatedSort(P, P_child, F[0]);
        show_domination_info(P, P_child, F[0]);*/
    }
    //file.close();
    return 0;
}