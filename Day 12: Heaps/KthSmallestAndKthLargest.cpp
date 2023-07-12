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

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;

	for(int i=0; i<n; i++){
		if(maxHeap.size() < k) maxHeap.push(arr[i]);
		else{
			if(arr[i] < maxHeap.top()){
				maxHeap.pop();
				maxHeap.push(arr[i]);
			}
		}


		if(minHeap.size() < k) minHeap.push(arr[i]);
		else{
			if(arr[i] > minHeap.top()){
				minHeap.pop();
				minHeap.push(arr[i]);
			}
		}
	}

	ans.push_back(maxHeap.top());
	ans.push_back(minHeap.top());
	return ans;
}

int main()
{
    return 0;
}