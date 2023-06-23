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

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if(!n) return 0;

    int ans = 1, currSize = 1;
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    for(auto num : s){
        if(s.find(num-1) == s.end()){
            currSize = 1;
            int temp = num;
            while(s.find(temp+1) != s.end()){
                currSize++;
                temp = temp + 1;
            }
        }

        ans = max(ans, currSize);
    }
    return ans;
}

int main()
{
    vector<int> arr = {100, 1, 3, 200, 5, 4};
    int ans = lengthOfLongestConsecutiveSequence(arr, arr.size());
    cout<<ans<<endl;
    return 0;
}