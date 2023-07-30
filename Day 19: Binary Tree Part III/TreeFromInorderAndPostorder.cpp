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

template<class T> class TreeNode
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
void createMapping(map<int, int> &m , vector<int> &inOrder){
    for(int i=0; i<inOrder.size(); i++){
        m[inOrder[i]] = i;
    }
}

void solve(TreeNode<int>* &root, vector<int>& postOrder, vector<int>& inOrder, int& index, int sIndex, int eIndex, map<int, int> &m){
    if(sIndex > eIndex || index<0) return;
    
    int element = postOrder[index--];
    root = new TreeNode<int>(element);
    
        solve(root->right, postOrder, inOrder, index, m[element]+1, eIndex, m);
    
    solve(root->left, postOrder, inOrder, index, sIndex, m[element]-1, m);
    

}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    TreeNode<int>* root = NULL;
    map<int, int> m;
    createMapping(m, inOrder);
    
    int index =inOrder.size()-1;
    int sIndex = 0;
    int eIndex = inOrder.size()-1;
    
    solve(root, postOrder, inOrder, index, sIndex, eIndex, m);
    return root;
}

int main()
{
    return 0;
}