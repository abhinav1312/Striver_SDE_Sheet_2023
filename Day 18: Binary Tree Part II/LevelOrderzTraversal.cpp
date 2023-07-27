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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> levelVec;
        
        
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode == NULL){
                ans.push_back(levelVec);
                levelVec.clear();
                if(!q.empty()) q.push(NULL);
            }else{
                levelVec.push_back(frontNode->val);
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            
        }

        return ans;
    }
};

int main()
{
    return 0;
}