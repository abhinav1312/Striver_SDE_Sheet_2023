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

void solve(BinaryTreeNode<int> * root, int dist, int lvl, map<int, pair<int, int>> &m){
    if(root==NULL) return;

    if(m.find(dist) != m.end()){
        if(m[dist].first <= lvl) m[dist] = {lvl, root->data};
    }
    else{
        m[dist] = {lvl, root->data};
    }
    
    solve(root->left, dist-1, lvl+1, m);
    solve(root->right, dist+1, lvl+1, m);
}

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    map<int, pair<int, int>> m;
    solve(root, 0, 0, m);
    for(auto pr : m){
        ans.push_back(pr.second.second);
    }

    return ans;
    
}

int main()
{
    return 0;
}