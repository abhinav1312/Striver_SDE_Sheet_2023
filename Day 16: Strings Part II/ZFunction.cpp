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

vector<int> search(string text, string pattern) {
    vector<int> ans;
	for(int i=0; i<=text.size()-pattern.size(); i++){
		if(text.substr(i, pattern.size()) == pattern) ans.push_back(i+1);
	}
	return ans;
}

int main()
{
    return 0;
}