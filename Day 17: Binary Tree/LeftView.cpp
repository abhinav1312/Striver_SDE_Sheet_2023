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



void solve(TreeNode<int> *root, int lvl, unordered_map<int, bool> &visited, vector<int> &ans){
    if(root == NULL) return;

    if(visited.find(lvl) == visited.end()){
        ans.push_back(root->data);
        visited[lvl] = 1;
    }
    solve(root->left, lvl+1, visited, ans);
    solve(root->right, lvl+1, visited, ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    unordered_map<int, bool> m; //check if level's element is in ans
    vector<int> ans;
    solve(root, 0, m, ans);
    return ans;
}

int main()
{
    return 0;
}