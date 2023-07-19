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

string reverseString(string &str){
	vector<string> vec;
	string ans = "";
	int n = str.length();
	for(int i=0;i<n;i++){
		string temp="";
		while(!isspace(str[i]) && i<n){
		    temp.push_back(str[i++]);
		}
		if(!temp.empty()){
		    vec.push_back(temp);
		}
	}

	for(int i=vec.size()-1;i>=0;i--){
		ans.append(vec[i]);
		if(i>0)ans.append(" ");
	}

	return ans;
}

int main()
{
    return 0;
}