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

int longestSubSeg(vector<int> &arr , int n, int k){
    int cntZero=0, currSize=0, maxSize=0, left = 0, right = 0;
    
    // sliding window approach
    while(right < n){
        if(arr[right] == 0) cntZero++;;
        
        while(cntZero > k){
            if(arr[left] == 0) cntZero--;
            left++;
        }

        maxSize = max(maxSize, right+1-left);
        right++;
    }

    return maxSize;

}


int main()
{
    vector<int> arr = {1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1};
    int ans = longestSubSeg(arr, arr.size(), 3);
    cout<<ans<<endl;
    return 0;
}