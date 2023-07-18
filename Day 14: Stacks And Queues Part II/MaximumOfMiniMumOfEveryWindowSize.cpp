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

void findPrevSmaller(vector<int> &a, int n, vector<int> &prevSmallerIndex){
    stack<int> s;
    s.push(-1);
    for(int i=0; i<n; i++){
        while(s.size() != 1 && a[i] <= a[s.top()]) s.pop();
        prevSmallerIndex[i] = s.top();
        s.push(i);
    }
}
void findNextSmaller(vector<int> &a, int n, vector<int> &nextSmallerIndex){
    stack<int> s;
    s.push(n);
    for(int i=n-1; i>=0; i--){
        while(s.size() != 1 && a[i] <= a[s.top()]) s.pop();
        nextSmallerIndex[i] = s.top();
        s.push(i);
    }
}

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> prevSmallerIndex(n);
    vector<int> nextSmallerIndex(n);

    findPrevSmaller(a, n, prevSmallerIndex);
    findNextSmaller(a, n, nextSmallerIndex);

    vector<int> ans(n, INT_MIN);
    for(int i=0; i<n; i++){
        int probableWindow = nextSmallerIndex[i] - prevSmallerIndex[i] - 1;
        ans[probableWindow-1] = a[i] > ans[probableWindow-1] ? a[i] : ans[probableWindow-1];
    }
    int temp = ans[n-1];
    for(int i=n-2; i-1>=0; i--){
        if(ans[i] > temp) temp = ans[i];
        ans[i] = temp;
    }
    return ans;
}

int main()
{
    return 0;
}