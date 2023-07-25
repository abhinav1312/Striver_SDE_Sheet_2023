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

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

void verticalTraverse(TreeNode<int>* root, map<int, map<int, vector<int> > > &m, int vd, int lvl){
    if(!root) return;
    
    m[vd][lvl].push_back(root->data);
    if(root->left){
        verticalTraverse(root->left, m, vd-1, lvl+1);
    }
    if(root->right){
        verticalTraverse(root->right, m, vd+1, lvl+1);
    }
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    
    map<int, map<int, vector<int> > > m;
    vector<int> ans;
    int vd=0, lvl=0;
    if(!root) return ans;
    verticalTraverse(root, m, vd, lvl);
    
    for(auto pr1 : m){
        for(auto pr2 : pr1.second){
            for(auto ele: pr2.second){
                ans.push_back(ele);
            }
        }
    }
    
    return ans;
}

int main()
{
    return 0;
}