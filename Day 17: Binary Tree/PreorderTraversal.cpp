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

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode* pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }

            if(pre->right == NULL){
                ans.push_back(curr->data);
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}