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

long long maxSubarraySum(int arr[], int n)
{
    // empty array
    if(n==0) return 0;

    long long maxSum = 0;
    long long currSum = 0;
    for(int i=0; i<n; i++){
        currSum = currSum + arr[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0) currSum = 0;
    }

    return maxSum;
}

int main()
{
    int arr[5] = {1, 2, -5, 3, 4};
    int maxSum = maxSubarraySum(arr, 5);
    cout<<maxSum<<endl;
    return 0;
}