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

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<int> cnt(n+1); // keep count of the elemets
	int repeatedNum = -1;
	for(int i=0; i<n; i++){
		cnt[arr[i]]++;

		if(cnt[arr[i]] > 1){
			repeatedNum = arr[i];
			break;
		}
	}

	int arrSum = 0; // count sum of elements of array
	for(int i=0; i<n; i++){
		arrSum += arr[i];
	}

	int sumWithoutRepeat = arrSum - repeatedNum;

	int apSum = (n*(1 + n))/2;
	return make_pair(apSum - sumWithoutRepeat, repeatedNum);
}


int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);

    pair<int, int> ans = missingAndRepeating(arr, 3);
    cout<<"Missing num: "<<ans.first<<endl;
    cout<<"Repeated num: "<<ans.second<<endl;
    return 0;
}