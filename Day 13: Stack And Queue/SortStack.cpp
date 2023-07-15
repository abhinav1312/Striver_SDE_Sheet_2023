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

void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;

	int top = stack.top();
	stack.pop();
	sortStack(stack);

	vector<int> v;
	while(!stack.empty() && top < stack.top()){
		v.push_back(stack.top());
		stack.pop();
	}
	stack.push(top);
	for(int i=v.size()-1; i>=0; i--){
		stack.push(v[i]);
	}
}

int main()
{
    return 0;
}