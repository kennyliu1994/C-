#include "lib.cpp"

const unsigned int n = 3;          //number of individual
const unsigned int s = 1;          //sign bit
const unsigned int pl = 3;         //point left
const unsigned int pr = 2;         //point right
unsigned int m = s + pl + pr;      //Q-bit individual 長度
unsigned int t;                    //目前第幾代
const unsigned int iteration = 25; //總迭代數

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
    void make(class individual parent[n], class individual child[n])
    {
        rand_Kenny rd;
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                if (rd.range_double_1(0, 1.0) < pow(parent[i].beta[j], 2))
                    child[i].content[j] = 1;
                else
                    child[i].content[j] = 0;
            }
        }
    }
    void evaluate(class individual indi[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            convert binvec2dec(indi[i].content, indi[i].decimal, pl);
            indi[i].fitness = obj(indi[i].decimal);
        }
    }
    void show(class individual indi[n], unsigned int t)
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
            cout << " , fitness = " << indi[i].fitness << endl
                 << endl;
        }
    }
    void firstStore(class individual indi[n], class individual B[n])
    {
        for (unsigned int i = 0; i < n; i++) //因為第一迭代，複製一份P(0)到B作為B的初始化
        {
            B[i].alpha.assign(indi[i].alpha.begin(), indi[i].alpha.end());
            B[i].beta.assign(indi[i].beta.begin(), indi[i].beta.end());
            B[i].content.assign(indi[i].content.begin(), indi[i].content.end());
            B[i].decimal = indi[i].decimal;
            B[i].fitness = indi[i].fitness;
        }
    }
    void update(class individual child[n], class individual B[n])
    {
        double theta;
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                theta = lookup(child[i].content[j], B[i].content[j], child[i].fitness, B[i].fitness);
                if (child[i].alpha[j] * child[i].beta[j] > 0)
                    theta = -theta;
                child[i].alpha[j] = cos(theta) * child[i].alpha[j] - sin(theta) * child[i].beta[j];
                child[i].beta[j] = sin(theta) * child[i].alpha[j] + cos(theta) * child[i].beta[j];
            }
        }
    }
    void store(class individual child[n], class individual B[n])
    {
        for (unsigned int i = 0; i < n; i++)
        {
            comp.push_back(B[i]);
            comp.push_back(child[i]);
        }
        sort(comp.begin(), comp.end(), cmp); //對整個class的某項參數作為依據排序
        for (unsigned int i = 0; i < n; i++)
        {
            B[i].alpha.assign(comp[i].alpha.begin(), comp[i].alpha.end());
            B[i].beta.assign(comp[i].beta.begin(), comp[i].beta.end());
            B[i].content.assign(comp[i].content.begin(), comp[i].content.end()); //取排序的一半存到B
            B[i].decimal = comp[i].decimal;
            B[i].fitness = comp[i].fitness;
        }
    }

  private:
    vector<individual> comp; //class存到vector做比較用
    double obj(double x)
    {
        return 10 + (pow(x, 2) - 10 * cos(2 * M_PI * x));
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
    static bool cmp(individual const &a, individual const &b)
    {
        return a.fitness < b.fitness;
    };
};
int main()
{
    srand((unsigned)time(NULL));
    QEA test;
    individual indi[n];    //n個個體
    test.initialize(indi); //初始化個體
    test.make(indi, indi); //觀察Q得到P
    test.evaluate(indi);   //用P算期望值
    //test.show(indi, t);    //show Q(0) & P(0)
    individual B[n];
    test.initialize(B);
    test.firstStore(indi, B);
    //test.show(B, t);          //show B(0)
    individual indi_child[n]; //P的child，文章中為P(t)
    while (t < iteration)
    {
        t++;
        test.initialize(indi_child);
        test.make(indi, indi_child);
        test.evaluate(indi_child);
        //test.show(indi_child, t);
        test.update(indi_child, B);
        //test.show(indi_child, t);
        test.store(indi_child, B);
        test.show(B, t);
        for (unsigned int i = 0; i < n; i++) //小孩變成父母
        {
            indi[i] = indi_child[i];
        }
    }
    //test.show(B, t);
    return 0;
}