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

long getTrappedWater(long *arr, int n){
    long leftMax = 0, rightMax = 0, left = 0, right = n-1;
        long ans = 0;
        while(left < right){
            if(arr[left] < arr[right]){
                leftMax = max(leftMax, arr[left]);
                long waterAtPresent = leftMax - arr[left];
                ans += waterAtPresent;
                left++;
            }
            else{
                rightMax = max(rightMax, arr[right]);
                long waterAtPresent = rightMax - arr[right];
                ans += waterAtPresent;
                right--;
            }
        }
        
        return ans;
}

int main()
{
    long v[] = {3, 1, 1, 2, 5, 2, 4};
    long ans = getTrappedWater(v, 8);
    cout<<ans<<endl;
    return 0;
}