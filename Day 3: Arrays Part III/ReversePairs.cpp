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

int cnt = 0;
void countPairs(vector<int> &arr, int n, int low, int mid, int high){
	int left = low, right = mid+1;
	while(left<=mid && right<=high){
		if(arr[left] > 2*arr[right]){
			cnt = cnt + (mid-left+1);
			right++;
		}
		else{
			left++;
		}
	}
}

void merge(vector<int> &arr, int n, int low, int mid, int high){
	int left=low, right=mid+1;
    vector<int> temp;

    //  cout<<"Count pairs low "<<endl;
    // for(int i=low; i<=mid; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    // cout<<"Count pairs high "<<endl;
    // for(int i=mid+1; i<=high; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    // cout<<endl;


    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }

    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    while(right <= high){
        temp.push_back(arr[right++]);
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &arr, int n, int low, int high){ 
	// only one element in the hypothetical array
	if(low>=high) return;
	
	int mid = low + (high-low)/2;
	mergeSort(arr, n, low, mid);
	mergeSort(arr, n, mid+1, high);
	
	countPairs(arr, n, low, mid, high);

	merge(arr, n, low, mid, high);
}

int reversePairs(vector<int> &arr, int n){
	mergeSort(arr, n, 0, n-1);	
	return cnt;
}

void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(1);

    int ans = reversePairs(arr, 5);
    cout<<ans<<endl;


    return 0;
}