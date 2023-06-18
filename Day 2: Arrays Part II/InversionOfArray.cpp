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

long long cnt = 0;

void merge(long long *arr, long long low, long long mid, long long high) {
  vector<int> temp;
    int left = low, right = mid+1;
    while(left<=mid && right<=high){
      if(arr[left]<=arr[right]){
        temp.push_back(arr[left]);
        left++;
      }
      else{
        temp.push_back(arr[right]);
        cnt = cnt + mid - left + 1;
        right++;
      }
    }

    while(left<=mid){
      temp.push_back(arr[left]);
      left++;
    }

    while(right<=high){
      temp.push_back(arr[right]);
      right++;
    }

    for(int i=low; i<=high; i++){
      arr[i] = temp[i-low];
    }

}

void mergeSort(long long *arr, long long low, long long high){
    if(low>=high) return;
    long long mid = (high+low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

long long getInversions(long long *arr, int n){
    long long low = 0; long long high = n-1;
    mergeSort(arr, low, high);
    return cnt;
}

int main()
{
    long long arr[5] = {3, 1, 4, 2, 5};
    int ans = getInversions(arr, 5);
    cout<<ans<<endl;
    return 0;
}