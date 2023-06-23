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

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> >  ans;

        int n=nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n; j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1;
                while(k != j+1 && nums[k] == nums[k-1]) k++;
                int l = n-1;
                while(l != n-1 && nums[l] == nums[l+1]) l--;

                while(k<l){
                    long long sum = 0ll +  nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target){
                        k++;
                        while(k < l && nums[k] == nums[k-1]) k++;
                    }
                    else{
                        l--;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}