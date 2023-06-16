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
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        if(!numRows) return ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        for(int i=1; i<numRows; i++){
            vector<int> temp;
            for(int j=0; j<=i; j++){
                int leftPrev = (i-1 >= 0 && j-1>=0 && j-1<ans[i-1].size()) ? ans[i-1][j-1] : 0;
                int rightPrev = (i-1 >= 0 && j>=0 && j<ans[i-1].size()) ? ans[i-1][j] : 0;
                int currNum = leftPrev + rightPrev;
                temp.push_back(currNum);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

void print(vector<vector<int> > &v ){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Solution s;
    vector<vector<int> > v = s.generate(5);
    print(v);
    return 0;
}