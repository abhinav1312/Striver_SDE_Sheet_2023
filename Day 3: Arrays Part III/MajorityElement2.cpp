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



vector<int> majorityElementII(vector<int> &arr)
{
    // moore's voting algorithm
    vector<int> ans;
    int n=arr.size(), probMajElem1, probMajElem2, cntElem1=0, cntElem2=0; 

    for(int i=0; i<n; i++){
        if(cntElem1 == 0){
            if(probMajElem2 && arr[i] == probMajElem2){
                cntElem2++;
            }
            else{
                cntElem1++;
                probMajElem1 = arr[i];
            }
        }
        else if(cntElem2 == 0){
            if(probMajElem1 && arr[i] == probMajElem1){
                cntElem1++;
            }
            else{
                cntElem2++;
                probMajElem2 = arr[i];
            }
        }
        else if(arr[i] == probMajElem1) cntElem1++;
        else if(arr[i] == probMajElem2) cntElem2++;
        else{
            cntElem1--;
            cntElem2--;
        }
    }

    cntElem1=0, cntElem2=0;
    for(int i=0; i<n; i++){
        if(arr[i] == probMajElem1) cntElem1++;
        else if(arr[i] == probMajElem2) cntElem2++;
    }

    if(cntElem1 > n/3) ans.push_back(probMajElem1);
    if(cntElem2 > n/3) ans.push_back(probMajElem2);
    return ans;
}

void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[9] = {1, 1, 1, 1, 2, 2, 2, 2, 5};
    vector<int> v;
    for(int i=0; i<9; i++){
        v.push_back(arr[i]);
    }

    vector<int> ans = majorityElementII(v);
    print(ans);
    
    return 0;
}