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
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<vector<int>, vector<vector<int> > , cmp> minHeap;

    // insert k elemets in heap each from different array
    for(int i=0; i<k; i++){
        int elem = kArrays[i][0];
        int row = i;
        int col = 0;
        minHeap.push({elem, row, col});
    }

    while(!minHeap.empty()){
        vector<int> top = minHeap.top();
        minHeap.pop();
        int elem = top[0];
        int row = top[1];
        int col = top[2];
        
        // push elem in ans
        ans.push_back(elem);

        // push the element afte the popped element in minHeap
        if(col+1 < kArrays[row].size()) minHeap.push({kArrays[row][col+1], row, col+1});
    }

    return ans;

}


int main()
{
    return 0;
}