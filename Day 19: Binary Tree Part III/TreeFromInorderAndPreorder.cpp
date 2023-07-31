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

TreeNode<int> *help(vector<int> &inorder,int is,int ie,vector<int>&preorder,int ps,int pe){
    if(is>ie ||ps>pe)return NULL;
    int val=preorder[ps];
    TreeNode<int> *root=new TreeNode<int>(val);
    int ridx;
    for(int i=is;i<=ie;i++){
        if(inorder[i]==val){
            ridx=i;
            break;
        }
    }
    int lis=is;
    int lie=ridx-1;
    int ris=ridx+1;
    int rie=ie;
    int lps=ps+1;
    int lpe=lps+lie-lis;
    int rps=lpe+1;
    int rpe=pe;
    root->left=help(inorder,lis,lie,preorder,lps,lpe);
    root->right=help(inorder,ris,rie,preorder,rps,rpe);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    return help(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);
}

int main()
{
    return 0;
}