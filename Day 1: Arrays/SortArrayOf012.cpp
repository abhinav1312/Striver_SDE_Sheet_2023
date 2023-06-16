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

void sort012(vector<int> &nums){
    // vector empty
    if(!nums.size()) return;

    // applying dutch national flag algorithm
    int i = 0, j=0, k=nums.size()-1;

    while(j<=k){
        if(nums[j] == 0){
            swap(nums[j], nums[i]);
            i++;
            j++;
        }
        else if(nums[j] == 1){
            j++;
        }
        else{
            swap(nums[j], nums[k]);
            k--;
        }
    }
}

void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);

    sort012(nums);
    print(nums);
    return 0;
}