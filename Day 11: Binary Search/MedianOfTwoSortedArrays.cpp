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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1>n2)  return findMedianSortedArrays(nums2, nums1);

        // elements on left and right of array
        int partitionSize = (n1+n2+1)/2;

        // min no. of elements that can be taken from nums1
        int low = 0;

        // max. no. of elements that can be taken from nums1
        int high = n1;

        while(low <= high){
            // no. of elemts to take from nums1
            int cut1 = low + (high-low)/2;

            // no. of elemts to take from nums2
            int cut2 = partitionSize-cut1;
        
            // divide nums1 into l1-r1 and nums2 to l2-r2 
            // find max from l1, min from r1, max from l2, min from r2
            double l1 = cut1<=0 ? INT_MIN : nums1[cut1-1];
            double l2 = cut2<=0 ? INT_MIN : nums2[cut2-1];
            double r1 = cut1>=n1 ? INT_MAX : nums1[cut1];
            double r2 = cut2>=n2 ? INT_MAX : nums2[cut2];

            // l1-l2 form the left side of the hypothetical joined array
            // r1-r2 form the right side of the hypothetical joined array
            // so for array to be correct and in sorted order,  following conditons
            // have to be applied
            if(l1 > r2){
                high = cut1-1;
            }
            else if(l2 > r1){
                low = cut1+1;
            }
            else{
                // even no. of elements
                if((n1+n2) % 2 == 0){
                    double maxFromLeft = max(l1, l2);
                    double minFromRight = min(r1, r2);
                    double median = (maxFromLeft + minFromRight)/2;
                    return median;
                }
                else{
                    return max(l1, l2);
                }
            }
            
        }
        return 0;
    }

int main()
{
    return 0;
}