#include "lib.cpp"

const unsigned int n = 3;     //number of individual
const unsigned int s = 1;     //sign bit
const unsigned int pl = 2;    //point left
const unsigned int pr = 3;    //point right
unsigned int m = s + pl + pr; //Q-bit individual 長度
unsigned int t = 0;           //第幾代
unsigned int iteration = 1;

class individual
{
  public:
    vector<double> alpha;
    vector<double> beta;
    vector<double> content;
    double decimal;
    double fitness1;
    double fitness2;
    vector<double> Sp;
    unsigned int np;
    unsigned int index;

  private:
};

void initialize(individual indiv[n])
{
    for (unsigned int i = 0; i < n; i++)
    {
        indiv[i].alpha.resize(m, 1 / sqrt(2)); //Q(0)每個為根號2分之1
        indiv[i].beta.resize(m, 1 / sqrt(2));
        indiv[i].content.resize(m);
        indiv[i].decimal = 0.0;
        indiv[i].fitness1 = 0.0;
        indiv[i].fitness2 = 0.0;
        //indiv[i].Sp.resize(2 * n - 1);
        indiv[i].np = 0;
        indiv[i].index = 0;
    }
}
void make_P(individual Q[n], individual P[n])
{
    rand_Kenny rd;
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            if (rd.range_double_1(0, 1.0) < pow(Q[i].beta[j], 2))
                P[i].content[j] = 1;
            else
                P[i].content[j] = 0;
        }
    }
}
void show_Q(individual Q[n])
{
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "Q" << i << "(" << t << ").alpha = [";
        for (unsigned int j = 0; j < m - 1; j++)
        {
            cout << Q[i].alpha[j] << " , ";
        }
        cout << Q[i].alpha[m - 1] << "]" << endl;
        cout << "Q" << i << "(" << t << ").beta = [";
        for (unsigned int j = 0; j < m - 1; j++)
        {
            cout << Q[i].beta[j] << " , ";
        }
        cout << Q[i].beta[m - 1] << "]" << endl;
    }
}
void show_P(individual P[n])
{
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "P" << i << "(" << t << ") = ";
        for (unsigned int j = 0; j < m; j++)
            cout << P[i].content[j];
        cout << " , decimal = " << P[i].decimal;
        cout << " , fitness1 = " << P[i].fitness1;
        cout << " , fitness2 = " << P[i].fitness2 << endl;
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
void evaluate(individual P[n])
{
    for (unsigned int i = 0; i < n; i++)
    {
        convert binvec2dec(P[i].content, P[i].decimal, pl);
        P[i].fitness1 = obj1(P[i].decimal);
        P[i].fitness2 = obj2(P[i].decimal);
    }
}
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
            /*cout << P[i].fitness1 << " , " << P[i].fitness2 << " , " << P_child[j].fitness1 << " , " << P_child[j].fitness2 << endl;
            cout << dominate(P[i].fitness1, P[i].fitness2, P_child[j].fitness1, P_child[j].fitness2) << endl;
            cout << P_child[j].index << endl;*/
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
}
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
    file.open("output.txt", ios::out | ios::app); //開啟檔案
    if (file.fail())                              //檢查檔案是否成功開啟
    {
        cout << "Can't open file!\n";
        exit(1); //在不正常情形下，中斷程式的執行
    }
    individual Q[n]; //n qbit individuals
    initialize(Q);   //initialize Q(t)
    //show_Q(Q);
    individual P[n];
    initialize(P);
    make_P(Q, P); //make P(t) by Q(t)
    evaluate(P);
    show_P(P);
    individual P_child[n];
    vector<double> F[2 * n];
    while (t < iteration)
    {
        t++;
        initialize(P_child);
        make_P(Q, P_child); //make P_child(t) by Q(t)
        evaluate(P_child);
        show_P(P_child);
        fastNondominatedSort(P, P_child, F[0]);
        show_domination_info(P, P_child, F[0]);
    }

    /*
    /////////////////////////////////////////evaluate P(t), output
    double sum = 0.0;
    toDecimal(sum, P);
    //file << obj1(sum) << " " << obj2(sum) << endl;
    /////////////////////////////////////////store B(t), B
    vector<double> B(m);
    for (unsigned int i = 0; i < m; i++)
    {
        B[i] = P[i];
    }
    //show_B(B);
    double Best;
    /////////////////////////////////////////update
    if (obj1(sum) < obj2(sum))
    {
        Best = obj1(sum);
        update(P, B, obj1(sum), Best, Q);
    }
    else
    {
        Best = obj2(sum);
        update(P, B, obj2(sum), Best, Q);
    }
    //update(P, B, obj1(sum), Best, Q);
    //show_Q(Q);
    /////////////////////////////////////////for loop
    for (unsigned int i = 0; i < 100000; i++)
    {
        make_P(Q, P);
        //show_P(P);
        toDecimal(sum, P);
        //file << obj1(sum) << " " << obj2(sum) << endl;
        if ((obj1(sum) < Best) && (obj1(sum) < obj2(sum)))
        {
            for (unsigned int i = 0; i < m; i++)
            {
                B[i] = P[i];
                //show_B(B);
            }
            Best = obj1(sum);
            update(P, B, obj1(sum), Best, Q);
        }
        if ((obj2(sum) < Best) && (obj2(sum) < obj1(sum)))
        {
            for (unsigned int i = 0; i < m; i++)
            {
                B[i] = P[i];
                //show_B(B);
            }
            Best = obj2(sum);
            update(P, B, obj2(sum), Best, Q);
        }
        //show_Q(Q);
    }
    cout << Best << endl;
    /////////////////////////////////////////
    //file.close();
    //cout << theta << endl;*/
    return 0;
}