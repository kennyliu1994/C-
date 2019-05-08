#include <string>
#include <iostream>

using namespace std;

class nsga2
{
private:
    string dataName;
    unsigned int run;
    unsigned int iter;
    unsigned int dim;
    void paraInit();

public:
    nsga2(const string datasetName, const unsigned int run, const unsigned int iteration);
    void exe();
};
