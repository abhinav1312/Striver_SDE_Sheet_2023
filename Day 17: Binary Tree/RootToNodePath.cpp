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


template<class T> class BinaryTreeNode {
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
void solve(BinaryTreeNode < int > * root, vector<string> &ans, string path){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        path = path + " " + to_string(root->data);
        ans.push_back(path.substr(1));
        return;
    }
    path = path + " " + to_string(root->data);
    solve(root->left, ans, path);
    solve(root->right, ans, path);
}

vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    // Write your code here.
    vector<string> ans;
    string path="";
    solve(root, ans, path);
    return ans;
}

int main()
{
    return 0;
}