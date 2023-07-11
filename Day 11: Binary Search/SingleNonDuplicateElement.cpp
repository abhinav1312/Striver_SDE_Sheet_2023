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

int singleNonDuplicate(vector<int>& arr)
{
	if(arr.size() == 1) return arr[0];
	if(arr[0] != arr[1]) return arr[0];

	int s=0, e=arr.size()-1;
	int mid=s+(e-s)/2;
	while(s<=e){
		mid=s+(e-s)/2;
		if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
		if(mid%2 == 0 && arr[mid] == arr[mid+1]) s = mid+1;
		else if(mid%2 == 0 && arr[mid] != arr[mid+1]) e = mid-1;
		else if(mid%2 == 1 && arr[mid] == arr[mid-1]) s = mid+1;
		else if(mid%2 == 1 && arr[mid] != arr[mid-1]) e = mid-1;
	}

	return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4};
    int ans = singleNonDuplicate(arr);
    cout<<ans<<endl;
    return 0;
}