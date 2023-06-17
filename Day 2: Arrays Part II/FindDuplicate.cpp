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

int findDuplicate(vector<int> &arr, int n){
	vector<int> cnt(n);
	for(int i=0; i<n; i++){
		cnt[arr[i]]++;
		if(cnt[arr[i]] > 1) return arr[i];
	}

	return -1;
}


int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);

    int duplicateNum = findDuplicate(arr, 5);
    cout<<duplicateNum<<endl;
    return 0;
}