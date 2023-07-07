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

void helper(vector<int> &candidates, int target, int idx, vector<int> subset, vector<vector<int> > &ans){
	if(target == 0){
		ans.push_back(subset);
		return;
	}

	for(int i = idx; i<candidates.size(); i++){
		if(i != idx && candidates[i] == candidates[i-1]) continue;
		if(candidates[i] <= target){
			subset.push_back(candidates[i]);
			helper(candidates, target-candidates[i], i+1, subset, ans);
			subset.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());
	vector<vector<int> > ans;
	vector<int> subset;
	helper(arr, target, 0, subset, ans);
	return ans;
}

int main()
{
    return 0;
}