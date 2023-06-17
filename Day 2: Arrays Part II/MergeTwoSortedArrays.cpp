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

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i=m-1, j=n-1, k=m+n-1;

	while(i>=0 && j>=0){
		if(arr1[i] > arr2[j]){
			arr1[k] = arr1[i];
			i--;
		}
		else{
			arr1[k] = arr2[j];
			j--;
		}
		k--;
	}

	if(i<0){
		while(j>=0){
			arr1[k] = arr2[j];
			k--;
			j--;
		}
	}
	return arr1;
}

void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(0);
    arr1.push_back(0);

    vector<int> arr2;
    arr2.push_back(4);
    arr2.push_back(5);

    vector<int> ans = ninjaAndSortedArrays(arr1, arr2, 3, 2);
    print(ans);
    return 0;
}