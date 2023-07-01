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

class Node{
    public:
    int val;
    Node* next;
    Node* random;

    Node(int data){
        this->val = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL;
        Node* tail = newHead;
        Node* temp = head;
        unordered_map<Node*, Node*> m;
        int cnt=0;
        while(temp){
            Node* node = new Node(temp->val);
            m[temp] = node;
            if(newHead == NULL){
                newHead = node;
                tail = newHead;
            }
            else{
                tail->next = node;
                tail = tail->next;
            }
            temp = temp->next;
        }

        temp = head;
        tail = newHead;

        while(temp){
            if(temp->random != NULL){
                tail->random = m[temp->random];
            }
            temp = temp->next;
            tail = tail->next;
        }

        return newHead;
    }
};

int main()
{
    return 0;
}