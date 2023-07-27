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


pair<int, int> diameter(TreeNode<int>* root){
    if(!root) return make_pair(0,0);
    
    pair<int,int> left = diameter(root->left);
    pair<int,int> right = diameter(root->right);
    
    int leftDiam = left.first; //diameter at left
    int rightDiam = right.first; //diameter at right
    int curroDiam = left.second+ right.second; // dimter including this node
    
    return make_pair(max(leftDiam, max(rightDiam, curroDiam)), max(left.second, right.second) +1) ;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    return diameter(root).first;
}

int main()
{
    return 0;
}