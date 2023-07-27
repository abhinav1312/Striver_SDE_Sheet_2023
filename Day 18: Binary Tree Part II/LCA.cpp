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
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(!root) return -1;
    if(root->data == x) return x;
    if(root->data == y) return y;

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    if(left != -1 && right != -1) return root->data;
    if(left == -1 && right != -1) return right;
    if(left != -1 && right == -1) return left;
    return -1;
}

int main()
{
    return 0;
}