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

   template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void findLeft(TreeNode<int>* root, vector<int> &ans){
    if(!root) return;
    if(!root->left && !root->right) return;
    ans.push_back(root->data);
    if(root->left) findLeft(root->left, ans);
    else findLeft(root->right, ans);
}
void findRight(TreeNode<int>* root, vector<int> &ans){
    if(!root) return;
    if(!root->left && !root->right) return;
    ans.push_back(root->data);
    if(root->right) findRight(root->right, ans);
    else findRight(root->left, ans);
}
void findChild(TreeNode<int>* root, vector<int> &ans){
    if(!root) return;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    };
    findChild(root->left, ans);
    findChild(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root) return ans;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return ans;
    }

    ans.push_back(root->data);
    findLeft(root->left, ans);
    findChild(root, ans);
    int n = ans.size();
    findRight(root->right, ans);
    reverse(ans.begin()+n, ans.end());
    return ans;
}

int main()
{   
    return 0;
    return 0;
}