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

#include<stack>
vector<int> findNextSmaller(vector<int> &heights, int n){
    stack<int> st;
    vector<int> res(n);
    st.push(n);
    for(int i=n-1; i>=0; i--){
        int temp = heights[i];
        while(st.size()!=1 && temp <= heights[st.top()]){
            st.pop();
        }
        res[i] = st.top();
        st.push(i);
    }   
    return res;
}
vector<int> findPrevSmaller(vector<int> &heights, int n){
    stack<int> st;
    vector<int> res;
    st.push(-1);
    for(int i=0; i<n; i++){
        int temp = heights[i];
        while(st.size()!=1 && temp <= heights[st.top()]){
            st.pop();
        }
        res.push_back(st.top());
        st.push(i);
    }   
    return res;
}

int largestRectangle(vector < int > & heights) {
    int n = heights.size();
    vector<int> nextSmaller = findNextSmaller(heights, n);
    vector<int> prevSmaller = findPrevSmaller(heights, n);

    int maxArea = 0;
    for(int i=0; i<n; i++){
        int currArea = (nextSmaller[i] - prevSmaller[i] - 1) * heights[i];
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

int main()
{
    return 0;
}