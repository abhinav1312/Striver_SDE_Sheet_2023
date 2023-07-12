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

class cmp{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> minHeap;

    for(auto pair : m){
        if(minHeap.size() < k) minHeap.push(pair);
        else{
            if(pair.second > minHeap.top().second){
                minHeap.pop();
                minHeap.push(pair);
            }
        }
    }

    vector<int> ans;
    while(!minHeap.empty()){
        ans.push_back(minHeap.top().first);
        minHeap.pop();
    }

    return ans;

}

int main()
{
    return 0;
}