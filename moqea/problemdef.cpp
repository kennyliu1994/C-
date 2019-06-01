#include <math.h>
#include <iostream>

#include "global.h"

//#define sch1
//#define sch2
//#define fon
//#define kur
//#define pol
//#define vnt
//#define zdt1
//#define zdt2
//#define zdt3
//#define zdt4
//#define zdt5
//#define zdt6
//#define bnh
//#define osy
//#define srn
//#define tnk
//#define ctp1
//#define ctp2
//#define ctp3
//#define ctp4
//#define ctp5
//#define ctp6
//#define ctp7
//#define ctp8

/*  Test problem SCH1
    # of real variables = 1
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef sch1
void sch1(vector<double> &value, vector<double> &fitness)
{
    fitness[0] = pow(value[0], 2.0);
    fitness[1] = pow((value[0] - 2.0), 2.0);
    return;
}
//endif

/*  Test problem SCH2
    # of real variables = 1
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef sch2
void sch2(vector<double> &value, vector<double> &fitness)
{
    if (value[0] <= 1.0)
    {
        fitness[0] = -value[0];
        fitness[1] = pow((value[0] - 5.0), 2.0);
        return;
    }
    if (value[0] <= 3.0)
    {
        fitness[0] = value[0] - 2.0;
        fitness[1] = pow((value[0] - 5.0), 2.0);
        return;
    }
    if (value[0] <= 4.0)
    {
        fitness[0] = 4.0 - value[0];
        fitness[1] = pow((value[0] - 5.0), 2.0);
        return;
    }
    fitness[0] = value[0] - 4.0;
    fitness[1] = pow((value[0] - 5.0), 2.0);
    return;
}
//endif

/*  Test problem FON
    # of real variables = n
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef fon
void fon(vector<double> &value, vector<double> &fitness)
{
    double s1, s2;
    int i;
    s1 = s2 = 0.0;
    for (i = 0; i < dimension; i++)
    {
        s1 += pow((value[i] - (1.0 / sqrt((double)dimension))), 2.0);
        s2 += pow((value[i] + (1.0 / sqrt((double)dimension))), 2.0);
    }
    fitness[0] = 1.0 - exp(-s1);
    fitness[1] = 1.0 - exp(-s2);
    return;
}
//endif

/*  Test problem KUR
    # of real variables = 3
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef kur
void kur(vector<double> &value, vector<double> &fitness)
{
    int i;
    double res1, res2;
    res1 = -0.2 * sqrt((value[0] * value[0]) + (value[1] * value[1]));
    res2 = -0.2 * sqrt((value[1] * value[1]) + (value[2] * value[2]));
    fitness[0] = -10.0 * (exp(res1) + exp(res2));
    fitness[1] = 0.0;
    for (i = 0; i < 3; i++)
    {
        fitness[1] += pow(fabs(value[i]), 0.8) + 5.0 * sin(pow(value[i], 3.0));
    }
    return;
}
//endif

/*  Test problem POL
    # of real variables = 2
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef pol
void pol(vector<double> &value, vector<double> &fitness)
{
    double a1, a2, b1, b2;
    a1 = 0.5 * sin(1.0) - 2.0 * cos(1.0) + sin(2.0) - 1.5 * cos(2.0);
    a2 = 1.5 * sin(1.0) - cos(1.0) + 2.0 * sin(2.0) - 0.5 * cos(2.0);
    b1 = 0.5 * sin(value[0]) - 2.0 * cos(value[0]) + sin(value[1]) - 1.5 * cos(value[1]);
    b2 = 1.5 * sin(value[0]) - cos(value[0]) + 2.0 * sin(value[1]) - 0.5 * cos(value[1]);
    fitness[0] = 1.0 + pow((a1 - b1), 2.0) + pow((a2 - b2), 2.0);
    fitness[1] = pow((value[0] + 3.0), 2.0) + pow((value[1] + 1.0), 2.0);
    return;
}
//endif

/*  Test problem VNT
    # of real variables = 2
    # of bin variables = 0
    # of objectives = 3
    # of constraints = 0
    */

//#ifdef vnt
void vnt(vector<double> &value, vector<double> &fitness)
{
    fitness[0] = 0.5 * (value[0] * value[0] + value[1] * value[1]) + sin(value[0] * value[0] + value[1] * value[1]);
    fitness[1] = (pow((3.0 * value[0] - 2.0 * value[1] + 4.0), 2.0)) / 8.0 + (pow((value[0] - value[1] + 1.0), 2.0)) / 27.0 + 15.0;
    fitness[2] = 1.0 / (value[0] * value[0] + value[1] * value[1] + 1.0) - 1.1 * exp(-(value[0] * value[0] + value[1] * value[1]));
    return;
}
//endif

/*  Test problem ZDT1
    # of real variables = 30
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef zdt1
void zdt1(vector<double> &value, vector<double> &fitness)
{
    double f1, f2, g, h;
    int i;
    f1 = value[0];
    g = 0.0;
    for (i = 1; i < 30; i++)
    {
        g += value[i];
    }
    g = 9.0 * g / 29.0;
    g += 1.0;
    h = 1.0 - sqrt(f1 / g);
    f2 = g * h;
    fitness[0] = f1;
    fitness[1] = f2;
    return;
}
//endif

/*  Test problem ZDT2
    # of real variables = 30
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef zdt2
void zdt2(vector<double> &value, vector<double> &fitness)
{
    double f1, f2, g, h;
    int i;
    f1 = value[0];
    g = 0.0;
    for (i = 1; i < 30; i++)
    {
        g += value[i];
    }
    g = 9.0 * g / 29.0;
    g += 1.0;
    h = 1.0 - pow((f1 / g), 2.0);
    f2 = g * h;
    fitness[0] = f1;
    fitness[1] = f2;
    return;
}
//endif

/*  Test problem ZDT3
    # of real variables = 30
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef zdt3
void zdt3(vector<double> &value, vector<double> &fitness)
{
    double f1, f2, g, h;
    int i;
    f1 = value[0];
    g = 0.0;
    for (i = 1; i < 30; i++)
    {
        g += value[i];
    }
    g = 9.0 * g / 29.0;
    g += 1.0;
    h = 1.0 - sqrt(f1 / g) - (f1 / g) * sin(10.0 * M_PI * f1);
    f2 = g * h;
    fitness[0] = f1;
    fitness[1] = f2;
    return;
}
//endif

/*  Test problem ZDT4
    # of real variables = 10
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef zdt4
void zdt4(vector<double> &value, vector<double> &fitness)
{
    double f1, f2, g, h;
    int i;
    f1 = value[0];
    g = 0.0;
    for (i = 1; i < 10; i++)
    {
        g += value[i] * value[i] - 10.0 * cos(4.0 * M_PI * value[i]);
    }    
    g += 91.0;
    h = 1.0 - sqrt(f1 / g);
    f2 = g * h;
    fitness[0] = f1;
    fitness[1] = f2;
    return;
}
//endif

/*  Test problem ZDT5
    # of real variables = 0
    # of bin variables = 11
    # of bits for binvar1 = 30
    # of bits for binvar2-11 = 5
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef zdt5
/*void zdt5(vector<double> &value, vector<double> &fitness)
{
    int i, j;
    int u[11];
    int v[11];
    double f1, f2, g, h;
    for (i = 0; i < 11; i++)
    {
        u[i] = 0;
    }
    for (j = 0; j < 30; j++)
    {
        if (gene[0][j] == 1)
        {
            u[0]++;
        }
    }
    for (i = 1; i < 11; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (gene[i][j] == 1)
            {
                u[i]++;
            }
        }
    }
    f1 = 1.0 + u[0];
    for (i = 1; i < 11; i++)
    {
        if (u[i] < 5)
        {
            v[i] = 2 + u[i];
        }
        else
        {
            v[i] = 1;
        }
    }
    g = 0;
    for (i = 1; i < 11; i++)
    {
        g += v[i];
    }
    h = 1.0 / f1;
    f2 = g * h;
    fitness[0] = f1;
    fitness[1] = f2;
    return;
}*/
//endif

/*  Test problem ZDT6
    # of real variables = 10
    # of bin variables = 0
    # of objectives = 2
    # of constraints = 0
    */

//#ifdef zdt6
void zdt6(vector<double> &value, vector<double> &fitness)
{
    double f1, f2, g, h;
    int i;
    f1 = 1.0 - (exp(-4.0 * value[0])) * pow((sin(6.0 * M_PI * value[0])), 6.0);
    g = 0.0;
    for (i = 1; i < 10; i++)
    {
        g += value[i];
    }
    g = g / 9.0;
    g = pow(g, 0.25);
    g = 1.0 + 9.0 * g;
    h = 1.0 - pow((f1 / g), 2.0);
    f2 = g * h;
    fitness[0] = f1;
    fitness[1] = f2;
    return;
}
//endif
