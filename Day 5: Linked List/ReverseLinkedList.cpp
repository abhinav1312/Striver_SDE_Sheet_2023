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
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *reverseLinkedList(Node *head) 
{
    if(!head || !head->next) return head;

    Node* newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Node* newHead = reverseLinkedList(head);
    print(newHead);

    return 0;
}