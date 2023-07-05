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

void helper(vector<int> &num, int i, vector<int> &ans, int sum){
	if(i>=num.size()){
		ans.push_back(sum);
		return;
	} 
	helper(num, i+1, ans, sum);
	helper(num, i+1, ans, sum+num[i]);
}

vector<int> subsetSum(vector<int> &num){
	int sum=0;
	vector<int> ans;
	helper(num, 0, ans, sum);
	sort(ans.begin(), ans.end());
	return ans;
}

int main()
{
    return 0;
}