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

int removeDuplicates(vector<int> &arr, int n) {
	int i = 1;
        for(int temp : arr){
            if(temp != arr[i-1]){
                arr[i] = temp;
                i++;
            }
        }
        return i;
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 2, 4};
    int ans = removeDuplicates(v, v.size());
    cout<<ans<<endl;
    return 0;
}