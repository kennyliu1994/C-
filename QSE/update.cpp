#include "global.h"
#include "kenny_lib.h"

void update(individual Q[], individual B[], individual &b)
{
    kenny_rand rd;
    double delta;
    for (int i = 0; i < popsize; i++)
    {
        for (int k = 0; k < item; k++)
        {
            delta = ff_x * (ff_omega * Q[i].angle[k] + ff_c1 * rd.double11(0, 1) * (B[i].angle[k] - Q[i].angle[k]) + ff_c2 * rd.double11(0, 1) * (b.angle[k] - Q[i].angle[k]));
            if ((Q[i].x[k] != B[i].x[k]) || (Q[i].x[k] != b.x[k]))
            {
                Q[i].angle[k] += delta;
            }
        }
    }
}