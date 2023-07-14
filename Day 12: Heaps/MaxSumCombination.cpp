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

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int, vector<int>, greater<int> > minHeap;

	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			int sum = a[i] + b[j];
			if(minHeap.size() < k){
				minHeap.push(sum);
			}
			else{
				if(sum > minHeap.top()){
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}

	int size = minHeap.size();
	vector<int> ans(size);
	size--;
	while(!minHeap.empty()){
		ans[size--] = minHeap.top();
		minHeap.pop();
	}

	return ans;
}

int main()
{
    return 0;
}