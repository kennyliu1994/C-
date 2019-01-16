#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>  /* printf, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "kmeans.h"
using namespace std;

txtToVector::txtToVector(const char *inputTxt, vector<double> outputVector[], const int row, const int column)
{
    {
        fstream IrisData;
        IrisData.open(inputTxt, ios::in);
        if (!IrisData)
            cout << "File read failed!/n";
        string line;
        int lineNumber = 0; //column
        while (getline(IrisData, line))
        {
            stringstream ss(line);
            for (int i = 0; i < row; i++)
            {
                string word;
                getline(ss, word, ',');
                double value;
                convert test(word, value);
                outputVector[lineNumber].push_back(value);
                //cout << outputVector[lineNumber][i] << " ";
            }
            lineNumber++;
            //cout << endl;
        }
        //cout << lineNumber << endl;
        IrisData.close();
    }
}
int rand_Kenny::getFromRange(const int lowerBound, const int upperBound)
{
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}
convert::convert(string intput, int &output)
{
    stringstream ss(intput);
    ss >> output;
}
convert::convert(string intput, double &output)
{
    stringstream ss(intput);
    ss >> output;
}