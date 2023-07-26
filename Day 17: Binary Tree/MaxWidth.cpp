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
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

int getMaxWidth(TreeNode<int> *root)
{
    // // Write your code here.
    if(root == NULL) return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        ans = max(ans, size);
        for(int i=0; i<size; i++){
            TreeNode<int> *front = q.front();
            q.pop();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }

    return ans;
}

int main()
{
    return 0;
}