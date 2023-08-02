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
bool storParents(TreeNode<int> *root, stack<TreeNode<int> *> &parents,
                 TreeNode<int> *leaf) {
  parents.push(root);

  if (!root->left and !root->right) {
    if (root->data == leaf->data)
      return true;
    else
      parents.pop();
    return false;
  }

  if (root->left) {
    if (storParents(root->left, parents, leaf))
      return true;
  }

  if (root->right) {
    if (storParents(root->right, parents, leaf))
      return true;
  }

  parents.pop();
  return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
  if (!root)
    return NULL;

  stack<TreeNode<int> *> parents;
  storParents(root, parents, leaf);

  TreeNode<int> *head = parents.top();
  parents.pop();

  TreeNode<int> *par = head;
  while (!parents.empty()) {
    auto p = parents.top();
    parents.pop();

    if (p->right == head) {
      p->right = p->left;
      p->left = NULL;
    } else {
      p->left = NULL;
    }

    head->left = p;
    head = p;
  }

  return par;
}


int main()
{
    return 0;
}