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
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

vector<int> getTopView(TreeNode<int> *root) {
    map<int, int> m;
    vector<int> ans;
    if(root == NULL) return ans;

    queue<pair<int, TreeNode<int> *>> q;
    q.push({0, root});
    int dist = 0;
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            int dist = q.front().first;
            TreeNode<int> * node = q.front().second;
            q.pop();
            if(m.find(dist) == m.end()){
                m[dist] = node->val;
            }
            if(node->left){
                q.push({dist-1, node->left});
            }
            if(node->right){
              q.push({dist + 1, node->right});
            }
        }
    }

    for(auto pr : m){
        ans.push_back(pr.second);
    }
    return ans;
}

int main()
{
    return 0;
}