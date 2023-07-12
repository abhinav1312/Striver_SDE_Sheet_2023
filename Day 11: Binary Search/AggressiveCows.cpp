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

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = 0, high = stalls[stalls.size()-1]; // min and max dist b/w two cows
    int mid = low + (high-low)/2;
    int ans = -1;
    while(low <= high){
        mid = low + (high-low)/2;
        int prevPos = 0;
        int currCows = 1;
        
        for(int i=0; i<stalls.size(); i++){
            int currDist = stalls[i] - stalls[prevPos];
            if(currDist >= mid){
                currCows++;
                prevPos = i;
            }
        }

        if(currCows < k){
            high = mid-1;
        }
        else{
            ans = mid;
            low = mid+1;
        }
    }

    return ans;
}

int main()
{
    return 0;
}