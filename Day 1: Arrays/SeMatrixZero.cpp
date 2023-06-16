#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

void setZeros(vector<vector<int> > &matrix)
{
    vector<int> rowVec;
    vector<int> colVec;

    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowVec.push_back(i);
                colVec.push_back(j);
            }
        }
    }

    for (int i = 0; i < rowVec.size(); i++)
    {
        int rowToConvert = rowVec[i];
        for (int j = 0; j < cols; j++)
        {
            matrix[rowToConvert][j] = 0;
        }
    }

    for (int i = 0; i < colVec.size(); i++)
    {
        int colToConvert = colVec[i];
        for (int j = 0; j < rows; j++)
        {
            matrix[j][colToConvert] = 0;
        }
    }
}

void print(vector<vector<int> > &v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int> > v;
    int rows, cols;
    cin>>rows>>cols;
    for(int i=0; i<rows; i++){
        vector<int> temp;
        for(int j=0; j<cols; j++){
            int tempNum;
            cin>>tempNum;
            temp.push_back(tempNum);
        }
        v.push_back(temp);
    }

    setZeros(v);
    print(v);
    return 0;
}