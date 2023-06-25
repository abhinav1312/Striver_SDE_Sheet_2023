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

int subarraysXor(vector<int> &arr, int x)
{
    // keeping the count of element and no. of times if occured
    unordered_map<int, int> m;
    m[0] = 1;
    int xorVal = 0, maxSubarray = 0;

    for(int i=0; i<arr.size(); i++){
        int num = arr[i];
        xorVal = xorVal^num;
        int temp = xorVal^x;
        maxSubarray += m[temp];
        m[xorVal]++;
    }

    return maxSubarray;

}

int main()
{   
    vector<int> arr = {4, 2, 2, 6, 4, 4};
    int ans = subarraysXor(arr, 6);
    cout<<ans<<endl;
    return 0;
}