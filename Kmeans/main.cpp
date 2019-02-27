#include "lib.cpp"

const unsigned int n = 150; //number of individual
const unsigned int dim = 4; //dimension
const unsigned int k = 3;   //k-cluster
unsigned int iteration = 15;
const char *inputTxt = "IrisData.txt"; //input data
class individual
{
  public:
    vector<double> content; //individual coordinate
    unsigned int inGroup;   //in which group(0,1,2...)
    double sd;              //shortest distance to cluster

  private:
};
class centroid
{
  public:
    vector<double> content; //centroid coordinate
    unsigned int size;      //number of individual in each group

  private:
};
void inputData(individual iris[n])
{
    fstream fs;
    fs.open(inputTxt, ios::in);
    if (!fs)
        cout << "Can't open file/n";
    string line;                 //one line in txt
    unsigned int lineNumber = 0; //how many lines in txt
    while (getline(fs, line))
    {
        stringstream ss(line);
        for (unsigned int i = 0; i < dim; i++)
        {
            string word; //word in a line
            getline(ss, word, ',');
            double value;
            convert strToDouble(word, value); //string to double
            iris[lineNumber].content.push_back(value);
        }
        lineNumber++;
    }
    //cout << lineNumber << endl;
    fs.close();
}
void firstCentroid(individual iris[n], centroid c[k])
{
    vector<int> index;
    rand_Kenny rd;
    for (unsigned int i = 0; i < k; i++)
    {
        index.push_back(rd.range(1, n));
        c[i].content.assign(iris[index[i] - 1].content.begin(), iris[index[i] - 1].content.end());
        //cout << index[i] << endl;
    }
}
void shortest(individual iris[n], centroid c[k])
{
    SSE d;
    for (unsigned int i = 0; i < n; i++)
    {
        iris[i].sd = d.distance(iris[i].content, c[0].content);
        iris[i].inGroup = 0;
        for (unsigned int j = 0; j < k - 1; j++)
        {
            if (iris[i].sd > d.distance(iris[i].content, c[j + 1].content))
            {
                iris[i].sd = d.distance(iris[i].content, c[j + 1].content);
                iris[i].inGroup = j + 1;
            }
        }
    }
}
void resetCentroid(individual iris[n], centroid c[k])
{
    for (unsigned int i = 0; i < k; i++)
    {
        for (unsigned int j = 0; j < dim; j++)
            c[i].content[j] = 0.0;
        c[i].size = 0;
    }
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int m = 0; m < k; m++)
        {
            if (iris[i].inGroup == m)
            {
                for (unsigned int j = 0; j < dim; j++)
                    c[m].content[j] += iris[i].content[j];
                c[m].size++;
            }
        }
    }
    for (unsigned int i = 0; i < k; i++)
    {
        for (unsigned int j = 0; j < dim; j++)
            c[i].content[j] = c[i].content[j] / c[i].size;        
    }
}
void show(individual iris[n])
{
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "individual [" << i << "] = ";
        for (unsigned int j = 0; j < dim; j++)
            cout << iris[i].content[j] << " ";
        cout << endl;
        cout << "in group = " << iris[i].inGroup << endl;
    }
}
void show_c(centroid c[k])
{
    cout << k << " centroid = " << endl;
    for (unsigned int i = 0; i < k; i++)
    {
        for (unsigned int j = 0; j < dim; j++)
            cout << c[i].content[j] << " ";
        cout << endl;
    }
}
double show_SSE(individual iris[n])
{
    double SSE = 0;
    for (unsigned int i = 0; i < n; i++)
        SSE += iris[i].sd;
    return SSE;
}
int main()
{
    srand((unsigned)time(NULL));
    individual iris[n];
    centroid c[k];
    inputData(iris);
    firstCentroid(iris, c);
    //show_c(c);
    while (iteration > 0)
    {
        shortest(iris, c);
        cout << "SSE = " << show_SSE(iris) << endl;
        resetCentroid(iris, c);
        //show_c(c);
        iteration--;
    }
    return 0;
}