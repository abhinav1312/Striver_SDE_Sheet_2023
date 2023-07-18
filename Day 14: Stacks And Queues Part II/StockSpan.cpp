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

vector<int> findStockSpans(vector<int>& prices) {
    stack<int> s; // find prev greater index
    s.push(-1);
    vector<int> ans;
    for(int i=0; i<prices.size(); i++){
        int temp = prices[i];
        while(s.top() != -1 && temp > prices[s.top()]){
            s.pop();
        }

        ans.push_back(i-s.top());
        s.push(i);
    }

    return ans;
}


int main()
{
    return 0;
}