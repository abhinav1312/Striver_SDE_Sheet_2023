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

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    bool lToR = 1; // flag to check in which direction to go

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i=0; i<size; i++){
            TreeNode<int>* front = q.front();
            q.pop();
            if(lToR){
                temp[i] = front->data;
            }
            else{
                temp[size-i-1] = front->data;
            }

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

        lToR = !lToR;
        for(int i=0; i<size; i++){
            ans.push_back(temp[i]);
        }
    }

    return ans;
}

int main()
{
    return 0;
}