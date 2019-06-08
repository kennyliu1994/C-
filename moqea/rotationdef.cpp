#include "iostream" //was not declared in this scope
#include "math.h"

#include "global.h"
#include "rand.h"

void SSAA_sch1(chromosome &x, chromosome b, int domi)
{
    double array[] = {0, 0, 0.01, 0, 0.01, 0, 0, 0};
    vector<double> theta_set(array, array + 8);
    double theta;
    double delta_theta;
    int sign;
    for (int j = 0; j < dimension; j++)
    {
        for (int k = 0; k < nbit; k++)
        {
            if (x.gene[j][k] == 0)
            {
                if (b.gene[j][k] == 0) //0,0
                {
                    delta_theta = 0;
                    sign = 0;
                }
                else //0,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[2] * M_PI;
                        sign = 0;
                    }
                    else //true
                    {
                        delta_theta = theta_set[3] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = -1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
            }
            else
            {
                if (b.gene[j][k] == 0) //1,0
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[4] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = -1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[5] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
                else //1,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[6] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[7] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
            }
            theta = sign * delta_theta;
            x.alpha[j][k] = cos(theta) * x.alpha[j][k] - sin(theta) * x.beta[j][k];
            x.beta[j][k] = sin(theta) * x.alpha[j][k] + cos(theta) * x.beta[j][k];
            //cerr<<x.alpha[j][k]<<endl;
            //cerr<<x.gene[j][k]<<" "<<best.gene[j][k]<<endl;
        }
    }
}

void MSAA_sch1(chromosome &x, chromosome b, int domi)
{
    //double array[] = {0, 0, 0, 0.05, 0.01, 0.025, 0.005, 0.025};
    //double array[] = {0.02, 0.04, 0.01, 0.02, 0.01, 0.02, 0, 0.01};
    double array[] = {0, 0, 0, 0.05, 0.01, 0.025, 0.005, 0.025};
    vector<double> theta_set(array, array + 8);
    double theta;
    double delta_theta;
    int sign;
    for (int j = 0; j < dimension; j++)
    {
        for (int k = 0; k < nbit; k++)
        {
            if (x.gene[j][k] == 0)
            {
                if (b.gene[j][k] == 0) //0,0
                {
                    delta_theta = 0;
                    sign = 0;
                }
                else //0,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[2] * M_PI;
                        sign = 0;
                    }
                    else //true
                    {
                        delta_theta = theta_set[3] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = -1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
            }
            else
            {
                if (b.gene[j][k] == 0) //1,0
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[4] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = -1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[5] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
                else //1,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[6] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[7] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
            }
            theta = sign * delta_theta;
            x.alpha[j][k] = cos(theta) * x.alpha[j][k] - sin(theta) * x.beta[j][k];
            x.beta[j][k] = sin(theta) * x.alpha[j][k] + cos(theta) * x.beta[j][k];
            //cerr<<x.alpha[j][k]<<endl;
            //cerr<<x.gene[j][k]<<" "<<best.gene[j][k]<<endl;
        }
    }
}

void GDAA_sch1_Xu_Wang(chromosome &x, chromosome b, int domi, int g)
{
    double temp;
    if (g <= ngen / 4)
    {
        temp = 0.05;
    }
    else if (g <= ngen / 2)
    {
        temp = 0.01;
    }
    else if (g <= 3 * ngen / 4)
    {
        temp = 0.005;
    }
    else
    {
        temp = 0.0025;
    }
    double array[] = {temp, temp, temp, temp, temp, temp, temp, temp};
    vector<double> theta_set(array, array + 8);
    double theta;
    double delta_theta;
    int sign;
    for (int j = 0; j < dimension; j++)
    {
        for (int k = 0; k < nbit; k++)
        {
            if (x.gene[j][k] == 0)
            {
                if (b.gene[j][k] == 0) //0,0
                {
                    delta_theta = 0;
                    sign = 0;
                }
                else //0,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[2] * M_PI;
                        sign = 0;
                    }
                    else //true
                    {
                        delta_theta = theta_set[3] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = -1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
            }
            else
            {
                if (b.gene[j][k] == 0) //1,0
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[4] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = -1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[5] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
                else //1,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[6] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[7] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else if (x.beta[j][k] == 0)
                        {
                            if (rand_double(0, 1) < 0.5)
                            {
                                sign = 1;
                            }
                            else
                            {
                                sign = -1;
                            }
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                }
            }
            theta = sign * delta_theta;
            x.alpha[j][k] = cos(theta) * x.alpha[j][k] - sin(theta) * x.beta[j][k];
            x.beta[j][k] = sin(theta) * x.alpha[j][k] + cos(theta) * x.beta[j][k];
            //cerr<<x.alpha[j][k]<<endl;
            //cerr<<x.gene[j][k]<<" "<<best.gene[j][k]<<endl;
        }
    }
}

void GDAA_sch2_Xu_Wang(chromosome &x, chromosome b, int domi, int g)
{
    double temp;
    if (g <= ngen / 4)
    {
        temp = 0.05;
    }
    else if (g <= ngen / 2)
    {
        temp = 0.01;
    }
    else if (g <= 3 * ngen / 4)
    {
        temp = 0.005;
    }
    else
    {
        temp = 0.0025;
    }
    double array[] = {temp, temp, temp, temp, temp, temp, temp, temp};
    vector<double> theta_set(array, array + 8);
    double theta;
    double delta_theta;
    int sign;
    for (int j = 0; j < dimension; j++)
    {
        for (int k = 0; k < nbit; k++)
        {
            if (x.gene[j][k] == 0)
            {
                if (b.gene[j][k] == 0) //0,0
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[0] * M_PI;
                        sign = 0;
                    }
                    else
                    {
                        delta_theta = theta_set[1] * M_PI;
                        sign = 0;
                    }
                }
                else //0,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[2] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[3] * M_PI;
                        sign = 0;
                    }
                }
            }
            else
            {
                if (b.gene[j][k] == 0) //1,0
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[4] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = -1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = 1;
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[5] * M_PI;
                        sign = 0;
                    }
                }
                else //1,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[6] * M_PI;
                        sign = 0;
                    }
                    else
                    {
                        delta_theta = theta_set[7] * M_PI;
                        sign = 0;
                    }
                }
            }
            theta = sign * delta_theta;
            x.alpha[j][k] = cos(theta) * x.alpha[j][k] - sin(theta) * x.beta[j][k];
            x.beta[j][k] = sin(theta) * x.alpha[j][k] + cos(theta) * x.beta[j][k];
            //cerr<<x.alpha[j][k]<<endl;
            //cerr<<x.gene[j][k]<<" "<<best.gene[j][k]<<endl;
        }
    }
}

void GDAA_sch2_Ji(chromosome &x, chromosome b, int domi, int g)
{
    double temp;
    double theta_max = 0.05;
    double theta_min = 0.0025;
    temp = theta_max - (theta_max - theta_min) * g / ngen;
    double array[] = {temp, temp, temp, temp, temp, temp, temp, temp};
    vector<double> theta_set(array, array + 8);
    double theta;
    double delta_theta;
    int sign;
    for (int j = 0; j < dimension; j++)
    {
        for (int k = 0; k < nbit; k++)
        {
            if (x.gene[j][k] == 0)
            {
                if (b.gene[j][k] == 0) //0,0
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[0] * M_PI;
                        sign = 0;
                    }
                    else
                    {
                        delta_theta = theta_set[1] * M_PI;
                        sign = 0;
                    }
                }
                else //0,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[2] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = 1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = -1;
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[3] * M_PI;
                        sign = 0;
                    }
                }
            }
            else
            {
                if (b.gene[j][k] == 0) //1,0
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[4] * M_PI;
                        if (x.alpha[j][k] * x.beta[j][k] > 0)
                        {
                            sign = -1;
                        }
                        else if (x.alpha[j][k] * x.beta[j][k] < 0)
                        {
                            sign = 1;
                        }
                        else
                        {
                            sign = 0;
                        }
                    }
                    else //true
                    {
                        delta_theta = theta_set[5] * M_PI;
                        sign = 0;
                    }
                }
                else //1,1
                {
                    if (domi == -1) //false
                    {
                        delta_theta = theta_set[6] * M_PI;
                        sign = 0;
                    }
                    else
                    {
                        delta_theta = theta_set[7] * M_PI;
                        sign = 0;
                    }
                }
            }
            theta = sign * delta_theta;
            x.alpha[j][k] = cos(theta) * x.alpha[j][k] - sin(theta) * x.beta[j][k];
            x.beta[j][k] = sin(theta) * x.alpha[j][k] + cos(theta) * x.beta[j][k];
            //cerr<<x.alpha[j][k]<<endl;
            //cerr<<x.gene[j][k]<<" "<<best.gene[j][k]<<endl;
        }
    }
}