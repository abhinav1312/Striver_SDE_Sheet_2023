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

void helper(vector<int> &arr, int n, int k, int i, vector<int> subset, vector<vector<int> > &ans, int target){
    if(i >= n ){
        if(target == k)
        ans.push_back(subset);
        return;
    }
    // skip the element
    helper(arr, n, k, i+1, subset, ans, target);

    // include
        subset.push_back(arr[i]);
        helper(arr, n, k, i+1, subset, ans, target+arr[i]);

}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int> > ans;
    vector<int> subset;
    helper(arr, n, k, 0, subset, ans, 0);
    return ans;
}

int main()
{
    return 0;
}


