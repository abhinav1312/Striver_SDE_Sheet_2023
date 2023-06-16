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

vector<int> reverse(vector<int> permutation, int s, int e){
    while(s<e){
        swap(permutation[s++], permutation[e--]);
    }

    return permutation;
}

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // Step1:  Find target index where number is smaller than its successor
    int targetIndex = -1;
    for(int i=n-1; i-1>=0; i--){
        if(permutation[i-1] < permutation[i]){
            targetIndex = i-1;
            break;
        }
    }

    // if  target index not found, i.e. the given number is the greatest
    // print the smallest permutation, i.e. reverse
    if(targetIndex == -1) return reverse(permutation, 0, n-1);

    // else, find a number from targetIndex+1 -> n, which is greaater than nums[targetIndex]
    // but smaller among the range
    int minIndex = targetIndex+1;
    for(int i=targetIndex+1; i<n; i++){
        if(permutation[i] > permutation[targetIndex] && permutation[i] <= permutation[minIndex]){
            minIndex = i;
        }
    }

    // swap the targetIndex's element and minIndex's element
    swap(permutation[targetIndex], permutation[minIndex]);

    // reverse and return
    return reverse(permutation, targetIndex+1, n-1);
}

void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> permutation;
    permutation.push_back(1);
    permutation.push_back(2);
    permutation.push_back(3);
    vector<int> ans = nextPermutation(permutation, permutation.size());
    print(ans);
    return 0;
}