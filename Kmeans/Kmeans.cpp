#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "kmeans.h"
using namespace std;

const int dimension = 4;
//const int numOfIndividuals = 150;
txtToVector::txtToVector(string inputTxt, vector<string> outputVector[numOfIndividuals])
{
    {
        fstream IrisData;
        IrisData.open("IrisData.txt", ios::in);
        if (!IrisData)
            cout << "File read failed!/n";
        string line;
        int lineNumber = 0;
        while (getline(IrisData, line))
        {
            istringstream ss(line);
            for (int i = 0; i < dimension; i++)
            {
                string word;
                getline(ss, word, ',');
                outputVector[lineNumber].push_back(word);
                //cout << outputVector[lineNumber][i] << " ";
            }
            lineNumber++;
            //cout << endl;
        }
        //cout << lineNumber << endl;
        IrisData.close();
    }
}
int main()
{
    vector<string> Iris[numOfIndividuals];
    txtToVector test("IrisData.txt", Iris);
    return 0;
}