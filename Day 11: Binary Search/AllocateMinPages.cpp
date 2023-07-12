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

bool isPossible(vector<int> &time, int n, long long mid, int days){
	int day = 1;
	long long currTime = 0;
	for(int i=0; i<n; i++){
		if(currTime + time[i] <= mid) currTime += time[i];
		else{
			day++;
			if(day > days || time[i] > mid) return false;

			currTime = time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long low = 0, high = 0;
	for(int i=0; i<m; i++){
		high += time[i];
	}
	long long mid = low + (high-low)/2;
	long long ans;

	while(low <= high){
		mid = low + (high-low)/2;
		if(isPossible(time, m, mid, n)){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}

	return ans;
}

int main()
{
    return 0;
}