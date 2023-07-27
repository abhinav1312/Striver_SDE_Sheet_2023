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

  template<class T>  class BinaryTreeNode 
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

pair<bool, int> solve(BinaryTreeNode<int>* root){
    if(!root) return {1, 0};
    
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);
    
    bool leftBalance = left.first;
    bool rightBalance = right.first;
    int leftDist = left.second;
    int rightDist = right.second;
    
    if(leftBalance && rightBalance && abs(leftDist-rightDist) <=1) return {true, max(leftDist, rightDist)+1};
    
    return {false, max(leftDist, rightDist)+1};
    
    
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return solve(root).first;
}

int main()
{
    return 0;
}