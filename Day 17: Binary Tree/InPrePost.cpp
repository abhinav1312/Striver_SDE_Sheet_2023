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

template <class T> class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

void solve(BinaryTreeNode<int> *root, vector<vector<int>> &v){
    if(root == NULL) return;

    v[1].push_back(root->data);
    solve(root->left, v);
    v[0].push_back(root->data);
    solve(root->right, v);
    v[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans(3);
    solve(root, ans);
    return ans;
}

int main()
{
    return 0;
}