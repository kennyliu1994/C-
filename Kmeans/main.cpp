#include <iostream>
#include <vector>
#include <string>
#include "kmeans.cpp"
using namespace std;

const int numOfIndividuals = 150;
const int dimension = 4;
int main()
{
    //string txtName("IrisData.txt");
    vector<string> Iris[numOfIndividuals];
    txtToVector test("IrisData.txt", Iris, dimension, numOfIndividuals);
    return 0;
}