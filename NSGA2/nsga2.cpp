#include "nsga2.h"

nsga2::nsga2(const string datasetName, const unsigned int run, const unsigned int iteration)
{
    this->dataName = datasetName;
    this->run = run;
    this->iter = iteration;
}
void nsga2::paraInit()
{
    if (dataName == "SCH")
    {
        dim = 1;
    }
}
void nsga2::exe()
{
    paraInit();
}