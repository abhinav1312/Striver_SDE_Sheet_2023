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

bool searchMatrix(vector<vector<int> >& mat, int target) {
    int rowS=0, rowE=mat.size()-1; // row start and row end
    int midRow = rowS + (rowE-rowS)/2;

    // outer binary search
    while(rowS<=rowE){
        midRow = rowS + (rowE-rowS)/2;
        if(mat[midRow][0] > target) rowE = midRow-1;
        else if(mat[midRow][0] < target){
            int s=0, e=mat[0].size()-1; // start and end columns
            int mid = s+(e-s)/2;

            // inner binary search
            while(s<=e){
                mid = s+(e-s)/2;
                if(mat[midRow][mid] > target) e = mid-1;
                else if(mat[midRow][mid] < target) s = mid+1;
                else return true;
            }
            rowS = midRow+1;
        }
        else return true;
    }
    return false;
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int> > mat(3, vector<int>(3));
    for(int i=0; i<9; i++){
        mat[i/3][i%3] = arr[i/3][i%3];
    }

    bool present = searchMatrix(mat, 5);
    cout<<present<<endl;
    return 0;
}