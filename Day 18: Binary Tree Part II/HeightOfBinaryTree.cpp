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

int maxDepth(TreeNode<int> *root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1+max(left, right);
}

int main()
{
    return 0;
}