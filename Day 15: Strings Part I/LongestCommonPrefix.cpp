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

bool comparator(string a, string b){
	return a.size() < b.size();
}

string commonPrefix(vector<string>& arr,int n){
	sort(arr.begin(), arr.end(), comparator);

	string prefix = arr[0];
	for(int i=1; i<n; i++){
		string temp = arr[i];
		temp = temp.substr(0, prefix.size());
		// cout<<"temp substr after: "<<temp<<endl;
		while(!prefix.empty() && temp != prefix){
			// cout<<"Debug: "<<prefix<<" "<<temp<<endl;
			temp.pop_back();
			prefix.pop_back();
		}
	}
	if(prefix.empty()) return "-1";
	return prefix;
}


int main()
{
    return 0;
}