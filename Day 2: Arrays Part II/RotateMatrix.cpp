#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
using namespace std;

// coding ninjas platform question
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top=0, bottom=n-1, left=0, right=m-1; 
    while(left<right && top<bottom){
        int temp = mat[top][left];

        // shift top row
        for(int i=left+1; i<=right; i++){
            // shift numbers 1 position ahead
            int k = mat[top][i];
            mat[top][i] = temp;
            temp = k;
        }
        top++;

        // shift right column
        for(int i=top; i<=bottom; i++){
            // shift numbers 1 position ahead
            int k = mat[i][right];
            mat[i][right] = temp;
            temp = k;
        }
        right--;

        // shift bottom row
        for(int i=right; i>=left; i--){
            // shift numbers 1 position ahead
            int k = mat[bottom][i];
            mat[bottom][i] = temp;
            temp = k;
        }
        bottom--;

        // shift right column
        for(int i=bottom; i>=top; i--){
            // shift numbers 1 position ahead
            int k = mat[i][left];
            mat[i][left] = temp;
            temp = k;
        }
        left++;

        mat[top-1][left-1] = temp;

    }
}


int main()
{   
    
    return 0;
}