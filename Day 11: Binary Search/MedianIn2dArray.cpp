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

int countFreq(vector<int> &v, int target){
    int s = 0, e = v.size()-1, mid = s + (e-s)/2;
    int ans=0;
    while(s <= e){
        mid = s + (e-s)/2;
        if(v[mid] <= target){
            ans = mid+1;
            s = mid+1;
        }
        else e = mid-1;
    }
    return ans;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int s = 0, e = 1e9;
    int probableMedian = s + (e-s)/2;
    int medianIndex = (m*n)/2; // index if array was 1D
    int ans = 0;
    while(s<=e){
        probableMedian = s + (e-s)/2;
        
        // find count of numbers smaller than probableMedian in the array
        int cnt = 0;
        for(int i=0; i<m; i++){
            cnt += countFreq(matrix[i], probableMedian);
        }

        if(cnt <= medianIndex) s = probableMedian+1;
        else if(cnt > medianIndex) e = probableMedian-1;
        else{
            ans = probableMedian;
            s = probableMedian+1;
        }
    }
    return s;
}

int main()
{
    return 0;
}