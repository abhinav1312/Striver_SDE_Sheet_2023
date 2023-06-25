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

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int listSize(Node* head){
    Node* temp = head;
    int size = 0;
    while(temp){
        size++;
        temp = temp->next;
    }
    return size;
}

Node* removeKthNode(Node* head, int K)
{
    if(K<=0) return head;

    // find size of linkedList
    int n = listSize(head);
    int indexToRemove = n-K;
    if(indexToRemove < 0) return head;
    if(indexToRemove == 0) return head->next;


    int cnt = 1;
    Node* temp = head;
    while(cnt < indexToRemove){
        temp = temp->next;
        cnt++;
    }

    temp->next = temp->next->next;

    return head;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Node* ans = removeKthNode(head, 2);
    print(ans);
    return 0;
}