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

void helper(vector<int> &arr, int n, int i, vector<vector<int> > &ans, vector<int> subset){
    ans.push_back(subset);

    for(int index = i; index<n; index++){
        if(index != i && arr[index] == arr[index-1]) continue;
        subset.push_back(arr[index]);
        helper(arr, n, index+1, ans, subset);
        subset.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{   
    vector<int> subset;
    vector<vector<int> > ans;
    sort(arr.begin(), arr.end());
    helper(arr, n, 0, ans, subset);
    return ans;
}

int main()
{
    return 0;
}