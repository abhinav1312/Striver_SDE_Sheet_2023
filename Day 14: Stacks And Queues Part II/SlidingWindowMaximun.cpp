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

#include<deque>
vector<int> maxSlidingWindow(vector<int> &arr, int n, int k){
    deque<int> dq;
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        // remove elemets outside boundary
        if(!dq.empty() && dq.back() == i-k) dq.pop_back();

        // remove elements from front until arr[i] < dq.front()
        while(!dq.empty() && arr[dq.front()] <= arr[i]) dq.pop_front();

        // push element index
        dq.push_front(i);

        // push in ans
        if(i>=k-1){
            ans.push_back(arr[dq.back()]);
        }
    }

    return ans;
}

int main()
{
    return 0;
}