#include "lib.cpp"

const unsigned int n = 3;           //number of individual
const unsigned int s = 1;           //sign bit
const unsigned int pl = 3;          //point left
const unsigned int pr = 2;          //point right
unsigned int m = s + pl + pr;       //Q-bit individual 長度
unsigned int t;                     //目前第幾代
const unsigned int iteration = 100; //總迭代數

class individual //Q,P,Pc
{
  public:
    vector<double> alpha;
    vector<double> beta;
    vector<double> content;
    double decimal;
    double fitness;

  private:
};
class QEA
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
            indi[i].fitness = 0.0;
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
            inid[i].fitness = obj(inid[i].decimal);
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
            cout << " , fitness1 = " << indi[i].fitness << endl;
        }
    };

  private:
    double obj(double x)
    {
        return 10 + (pow(x, 2) - 10 * cos(2 * M_PI * x));
    }
};
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
void update(vector<double> P, vector<double> B, double obj, double Best, individual indi)
{
    double theta;
    for (unsigned int i = 0; i < m; i++)
    {
        theta = lookup(P[i], B[i], obj, Best);
        if (indi.alpha[i] * indi.beta[i] > 0)
            theta = -theta;
        indi.alpha[i] = cos(theta) * indi.alpha[i] - sin(theta) * indi.beta[i];
        indi.beta[i] = sin(theta) * indi.alpha[i] + cos(theta) * indi.beta[i];
    }
}
bool cmp(individual const &a, individual const &b)
{
    return a.fitness < b.fitness;
}
int main()
{
    srand((unsigned)time(NULL));
    QEA test;
    individual indi[n];    //n個個體
    test.initialize(indi); //初始化個體
    test.make(indi, indi); //觀察Q得到P
    test.evaluate(indi);   //用P算期望值
    //test.show(indi);
    individual B[n];
    test.initialize(B);
    for (unsigned int i = 0; i < n; i++)
    {
        B[i].content.assign(indi[i].content.begin(), indi[i].content.end()); //因為第一迭代，複製一份P(0)到B作為B的初始化
        B[i].decimal = indi[i].decimal;
        B[i].fitness = indi[i].fitness;
    }
    //test.show(B);
    individual indi_child[n]; //P的child，文章中為P(t)
    test.initialize(indi_child);
    while (t < iteration)
    {
        t++;
        test.make(indi, indi_child);
        test.evaluate(indi_child); //test.show(indi_child);
        for (unsigned int i = 0; i < n; i++)
        {
            update(indi_child[i].content, B[i].content, indi_child[i].fitness, B[i].fitness, indi[i]); //更新Q
        }
        //test.show(indi_child);
        vector<individual> comp; //對整個class的某項參數作為依據排序
        for (unsigned int i = 0; i < n; i++)
        {
            comp.push_back(B[i]);
            comp.push_back(indi_child[i]);
        }
        sort(comp.begin(), comp.end(), cmp);
        /*for (unsigned int i = 0; i < 2*n; i++)
        {
            cout << comp[i].fitness << endl;
        }*/
        for (unsigned int i = 0; i < n; i++)
        {
            B[i].content.assign(comp[i].content.begin(), comp[i].content.end()); //取排序的一半存到B
            B[i].decimal = comp[i].decimal;
            B[i].fitness = comp[i].fitness;
        }
        for (unsigned int i = 0; i < n; i++) //小孩變成父母
        {
            indi[i] = indi_child[i];
        }
    }
    test.show(B);
    //file.close();
    return 0;
}