#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "kmeans.h"
using namespace std;

txtToVector::txtToVector(const char *inputTxt, vector<string> outputVector[], const int row, const int column)
{
    {
        fstream IrisData;
        IrisData.open(inputTxt, ios::in);
        if (!IrisData)
            cout << "File read failed!/n";
        string line;
        int lineNumber = 0;
        while (getline(IrisData, line))
        {
            istringstream ss(line);
            for (int i = 0; i < column; i++)
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