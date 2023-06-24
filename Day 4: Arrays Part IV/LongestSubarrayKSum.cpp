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


int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int, int> mp; // to store sum and index till index ;
    int sum = 0;
    int n = arr.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == 0) ans = i + 1;
        else if(mp.find(sum) != mp.end()) ans = max(ans, i-mp[sum]);
        else mp[sum] = i;
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, -1, 2, -2};
    int ans = LongestSubsetWithZeroSum(arr);
    cout<<ans<<endl;
    return 0;
}