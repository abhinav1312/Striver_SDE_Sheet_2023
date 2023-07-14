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

int signum(int a, int b){
	if(a > b) return 1;
	else if(a < b) return -1;
	return 0;
}

int avg(int a, int b){
	return (a+b)/2;
}

int findMedian(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap, int &median, int element){
	int choice = signum(maxHeap.size(), minHeap.size());

	switch(choice){
		case 0:
			// element > median
			if(element > median){
				minHeap.push(element);
				median = minHeap.top();
			}
			else{
				maxHeap.push(element);
				median = maxHeap.top();
			}
			break;
		
		case 1: 
			// element smaller than median
			if(element < median){
				int top = maxHeap.top();
				maxHeap.pop();
				minHeap.push(top);
				maxHeap.push(element);
				median = avg(minHeap.top(), maxHeap.top());
			}
			else{
				minHeap.push(element);
				median = avg(minHeap.top(), maxHeap.top());
			}
			break;
		
		case -1:
			// element > median 
			if(element > median){
				int top = minHeap.top();
				minHeap.pop();
				maxHeap.push(top);
				minHeap.push(element);
				median = avg(minHeap.top(), maxHeap.top());
			}
			else{
				maxHeap.push(element);
				median = avg(minHeap.top(), maxHeap.top());
			}
			break;
		
		default: 
			break;
	}

	return median;
}

vector<int> findMedian(vector<int> &arr, int n){
	
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	vector<int> ans;
	int median = 0;
	for(int i=0; i<n; i++){
		int med = findMedian(maxHeap, minHeap, median, arr[i]);
		ans.push_back(med);
	}
	return ans;
}

int main()
{
    return 0;
}