#include "kmeans.cpp"

const int numOfIndividuals = 150;
const int dimension = 4;
const int k = 3;
const char *inputTxt = "IrisData.txt";
class individual
{
  public:
    vector<double> content;
    unsigned int inWhichCluster; //0,1,2
    double distanceToCluster;

  private:
};
void initialization(individual iris[numOfIndividuals])
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
        for (unsigned int i = 0; i < dimension; i++)
        {
            string word;
            getline(ss, word, ',');
            double value;
            convert test(word, value);
            iris[lineNumber].content.push_back(value);
        }
        lineNumber++;
    }
    //cout << lineNumber << endl;
    IrisData.close();
}
void firstCentroid(individual iris[numOfIndividuals], vector<double> centroid[k])
{
    vector<int> index;
    rand_Kenny rd;
    for (unsigned int i = 0; i < k; i++)
    {
        index.push_back(rd.getFromRange(1, numOfIndividuals));
        centroid[i].assign(iris[index[i] - 1].content.begin(), iris[index[i] - 1].content.end());
        //cout << index[i] << endl;
    }
}
void shortest(individual &iris, vector<double> centroid[k])
{
    euclidean d;
    iris.distanceToCluster = d.distance(iris.content, centroid[0]);
    iris.inWhichCluster = 0;
    for (unsigned int i = 0; i < k - 1; i++)
    {
        if (iris.distanceToCluster > d.distance(iris.content, centroid[i + 1]))
        {
            iris.distanceToCluster = d.distance(iris.content, centroid[i + 1]);
            iris.inWhichCluster = i + 1;
        }
    }
}
void resetCentroid(individual iris[numOfIndividuals], vector<double> centroid[k])
{
    for (unsigned int i = 0; i < k; i++)
    {
        for (unsigned int j = 0; j < dimension; j++)
            centroid[i][j] = 0.0;
    }
    for (unsigned int i = 0; i < numOfIndividuals; i++)
    {
        for (unsigned int m = 0; m < k; m++)
        {
            for (unsigned int j = 0; j < dimension; j++)
            {
                if (iris[i].inWhichCluster == m)
                    centroid[m][j] += iris[i].content[j];
                //cout << centroid[m][j] << " ";
            }
            //cout << endl;
        }
    }
    for (unsigned int i = 0; i < k; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            centroid[i][j] = centroid[i][j] / k;
            //cout << centroid[i][j] << " ";
        }
        //cout << endl;
    }
}
int main()
{
    //vector<double> iris[numOfIndividuals];
    //txtToVector txt("IrisData.txt", iris.content, dimension, numOfIndividuals);
    individual iris[numOfIndividuals];
    initialization(iris);
    srand((unsigned)time(NULL));
    vector<double> centroid[k];
    firstCentroid(iris, centroid);
    /*for (unsigned int i = 0; i < k; i++)
    {
        for (int j = 0; j < dimension; j++)
            cout << centroid[i][j] << " ";
        cout << endl;
    }*/
    for (unsigned int i = 0; i < numOfIndividuals; i++)
    {
        shortest(iris[i], centroid);
        /*for (int j = 0; j < dimension; j++)
        {
            cout << iris[i].content[j] << " ";
        }
        cout << endl;
        cout << iris[i].inWhichCluster << endl;*/
    }
    resetCentroid(iris, centroid);
    //function(centroid)
    //for loop
    //minimize sum distance

    return 0;
}