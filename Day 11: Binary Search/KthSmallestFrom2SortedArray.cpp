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

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {

    if(m > n) return ninjaAndLadoos(row2, row1, n, m, k);
    int low = max(0, k-n), high = min(k, m);

    while(low <= high){
        int cut1 = low + (high-low)/2;
        int cut2 = k-cut1;

        int l1 = cut1==0 ? INT_MIN : row1[cut1-1];
        int l2 = cut2==0 ?  INT_MIN : row2[cut2-1];
        int r1 = cut1==m ? INT_MAX : row1[cut1];
        int r2 = cut2==n ? INT_MAX : row2[cut2];

        if(l1 > r2){
            high = cut1-1;
        }
        else if(l2 > r1){
            low = cut1+1;
        }
        else{
            return max(l1, l2);
        }
    }
    return 0;
}

int main()
{
    return 0;
}