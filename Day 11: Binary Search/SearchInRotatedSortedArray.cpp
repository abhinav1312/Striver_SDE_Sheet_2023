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

int findPivot(int* arr, int n){
    int s = 0, e = n-1, mid;
    while(s<e){
        mid = s+(e-s)/2;
        if(arr[mid] >= arr[0]) s = mid+1;
        else e = mid;
    }
    return e;
}

int binarySearch(int* arr, int s, int e, int key){
    int mid;
    while(s<=e){
        mid = s + (e-s)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) s = mid+1;
        else e = mid-1;
    }

    return -1;
}

int search(int* arr, int n, int key) {
    // step 1: Find pivot index i.e. starting of the pivot
    int pivot = findPivot(arr, n);
    
    // find element in either of the partition
    if(key >= arr[pivot] && key <= arr[n-1]) return binarySearch(arr, pivot, n-1, key);
    return binarySearch(arr, 0, pivot-1, key);
}

int main()
{
    int arr[] = {100, 1, 2, 3};
    int ans = search(arr, 4, 100);
    cout<<ans<<endl;
    return 0;
}