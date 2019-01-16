#include "kmeans.cpp"

const int numOfIndividuals = 150;
const int dimension = 4;
const int k = 3;
int main()
{
    vector<double> iris[numOfIndividuals];
    txtToVector txt("IrisData.txt", iris, dimension, numOfIndividuals);
    srand((unsigned)time(NULL));
    vector<double> centroid[k];
    vector<int> index;
    rand_Kenny id;
    for (int i = 0; i < k; i++)
    {
        index.push_back(id.getFromRange(1, numOfIndividuals));
        centroid[i].assign(iris[index[i] - 1].begin(), iris[index[i] - 1].end());
        /*cout << index[i] << endl;
        for (int j = 0; j < dimension; j++)
            cout << centroid[i][j] << " ";
        cout << endl;*/
    }
    //function(min distance),return 0,1,2
    //individual.inWhichCluster=0,1,2
    //function(centroid)
    //for loop
    //minimize sum distance

    return 0;
}