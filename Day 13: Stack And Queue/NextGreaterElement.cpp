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

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	
	vector<int> ans(n);
	stack<int> st;
	st.push(-1);
	for(int i=n-1; i>=0; i--){
		int elem = arr[i];
		while(st.top() != -1 && elem >= st.top()){
			st.pop();
		}

		ans[i] = st.top();
		st.push(elem);
	}
	return ans;
}

int main()
{
    return 0;
}