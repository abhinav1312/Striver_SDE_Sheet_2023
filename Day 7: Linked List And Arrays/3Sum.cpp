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

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int> > ans;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(i>0 && arr[i] == arr[i-1]) continue;
            int j=i+1;
            int k = n-1;

            while(j<k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum > K) k--;
                else if(sum < K) j++;
                else{
                    ans.push_back({{arr[i], arr[j], arr[k]}});
                    j++;
                    k--;
                    while(j<k && arr[j] == arr[j-1]) j++;
                    while(j<k && arr[k] == arr[k+1]) k--;
                } 
            }
        }

        return ans;
}

void print(vector<vector<int> > &v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; i<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> v = {1, 1, 2, 2, 1, 1};
    vector<vector<int> > ans = findTriplets(v, 6, 4);
    print(ans);
    return 0;
}